#include "DHT11_class.hpp"

DHT11_class::DHT11_class(uint8_t offset, const std::string &consumer_DHT)
    :offset_(offset), consumer_(consumer_DHT), chip_(chip0)
{
    line_ = gpiod_chip_get_line(chip_, DHT_GPIO);
    if (!line_) { gpiod_chip_close(chip_); return ; }

}


DHT11_class::~DHT11_class(){}

static int getDigitFromIntPart(double value, int positionFromRight) {
    int intPart = static_cast<int>(value);
    for (int i = 1; i < positionFromRight; ++i) {
        intPart /= 10;
    }
    return intPart % 10;
}

static int getDigitFromDecimalPart(double value, int decimalPosition) {
    double fractional = value - std::floor(value);
    for (int i = 0; i < decimalPosition; ++i) {
        fractional *= 10;
    }
    return static_cast<int>(fractional) % 10;
}

static int pack5DigitsFromFloat(float* temperature, float* humidity) {
    int t_tens     = getDigitFromIntPart(*temperature, 2);
    int t_units    = getDigitFromIntPart(*temperature, 1);
    int t_decimal  = getDigitFromDecimalPart(*temperature, 1);

    int h_tens     = getDigitFromIntPart(*humidity, 2);
    int h_units    = getDigitFromIntPart(*humidity, 1);

    int result = t_tens * 10000 + t_units * 1000 + t_decimal * 100 + (h_tens * 10 + h_units)/2;

    return result;
}

static void delay_ms(int ms) { usleep(ms * 1000); }
static void delay_us(int us) { usleep(us); }
int DHT11_class::MT_check(){
    struct gpiod_line_event evt;
    struct timespec ts[MAX_EDGES];
    float hum=0, temp=0;
    float *humidity;
    float *temperature;
    int count = 0;

    gpiod_line_request_output(line_, consumer_.c_str(), 0);
    gpiod_line_set_value(line_, 0);
    delay_ms(20);
    gpiod_line_set_value(line_, 1);
    delay_us(30);
    gpiod_line_release(line_);

    if (gpiod_line_request_both_edges_events(line_, consumer_.c_str()) != 0) {
        perror("请求事件失败");
        return -1;
    }
    struct timespec timeout = { .tv_sec = 0,
                                .tv_nsec = RESPONSE_TIMEOUT_MS * 1000000 };
    while (count < MAX_EDGES) {
        int rv = gpiod_line_event_wait(line_, &timeout);
        if (rv <= 0) break;
        if (gpiod_line_event_read(line_, &evt) == 0) ts[count++] = evt.ts;
    }
    gpiod_line_release(line_);
    if (count < 66) return -1;

    uint8_t h_int = 0;
    for (int b = 0; b < 8; b++) {
        int idx = 2 + b*2 + 1;
        long dt = (ts[idx].tv_sec - ts[idx-1].tv_sec)*1000000 + (ts[idx].tv_nsec - ts[idx-1].tv_nsec)/1000;
        h_int = (h_int << 1) | (dt > LOGIC_THRESHOLD_US);
    }
    
    uint8_t t_int = 0, t_dec = 0;
    for (int b = 16; b < 24; b++) {
        int idx = 2 + b*2 + 1;
        long dt = (ts[idx].tv_sec - ts[idx-1].tv_sec)*1000000 + (ts[idx].tv_nsec - ts[idx-1].tv_nsec)/1000;
        t_int = (t_int << 1) | (dt > LOGIC_THRESHOLD_US);
    }
    for (int b = 24; b < 32; b++) {
        int idx = 2 + b*2 + 1;
        long dt = (ts[idx].tv_sec - ts[idx-1].tv_sec)*1000000 + (ts[idx].tv_nsec - ts[idx-1].tv_nsec)/1000;
        t_dec = (t_dec << 1) | (dt > LOGIC_THRESHOLD_US);
    }

    // *humidity    = h_int/5;
    // *temperature = (t_int + t_dec * 0.1f)/20;

    hum = h_int/ 5.0f;// ;
    temp = (t_int + t_dec * 0.1f)/ 20.0f;// ;
    
    int packed = pack5DigitsFromFloat(&temp, &hum);
    // std::cout<<packed<<std::endl;
    return packed;
}