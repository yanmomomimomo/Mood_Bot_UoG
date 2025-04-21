#include "SYS.hpp"
#include "fonts.h"

uint8_t displayBuffer[BUFFER_SIZE];

static std::string GetDate() {
    std::time_t now = std::time(nullptr);
    std::tm* local = std::localtime(&now);

    int day   = local->tm_mday;
    int month = local->tm_mon;         // 0-11
    int year  = 1900 + local->tm_year;
    int wday  = local->tm_wday;        // 0=Sunday

    std::ostringstream oss;

    oss << std::setw(2) << std::setfill('0') << day;
    oss << MONTHS[month];
    oss << year;

    std::string weekday = WEEKDAYS[wday];
    oss << weekday;
    if (weekday.length() < 4)
        oss << ' ';

    return oss.str();
}

static void OLED_setPixel(int x, int y, bool on) {
    if (x < 0 || x >= OLED_WIDTH || y < 0 || y >= OLED_HEIGHT) {
        return;
    }
    int byteIndex = x + (y / 8) * OLED_WIDTH;
    int bitOffset = y % 8;
    if (on) {
        displayBuffer[byteIndex] |= (1 << bitOffset);
    } else {
        displayBuffer[byteIndex] &= ~(1 << bitOffset);
    }
}

static void DrawChar(int x, int y, char c, const sFONT *font) {
    int index = c - ' ';
    int width = font->Width;
    int height = font->Height;

    int bytesPerRow = (width + 7) / 8;

    const uint8_t *charData = font->table + index * height * bytesPerRow;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int byteIndex = row * bytesPerRow + (col / 8);
            int bitIndex  = 7 - (col % 8);  // 高位在左

            if (charData[byteIndex] & (1 << bitIndex)) {
                OLED_setPixel(x + col, y + row, 1);
            }
        }
    }

}

static void clearRegion(int x0, int y0, const sFONT *font) {
    int width = font->Width+1, height = font->Height;
    for (int y = y0; y < y0 + height; y++) {
        for (int x = x0; x < x0 + width; x++) {
            OLED_setPixel(x, y, 0);
        }
    }
}

static void clearall() {
    for (int y = 0; y < OLED_HEIGHT; y++) {
        for (int x = 0; x < OLED_WIDTH; x++) {
            OLED_setPixel(x, y, 0);
        }
    }
}

OLED_class::OLED_class()
    :devName_(I2C1_DEV)
{
    i2c_fd = open(devName_, O_RDWR);
    if (i2c_fd < 0) {
        std::cerr << "worning! :" << devName_ << " " << strerror(errno) << std::endl;
        return;
    }
    if (ioctl(i2c_fd, I2C_SLAVE, I2C1_ADDRESS) < 0) {
        std::cerr << "worning! :" << strerror(errno) << std::endl;
        close(i2c_fd);
        return;
    }
    if (!OLED_init()) {
        std::cerr << "worning! : OLED" << std::endl;
        close(i2c_fd);
        return;
    }
    OLED_clearDisplay();
    OLED_updateDisplay();

    Border_Show();
    Date_upgrade();
    TM_upgrade(12345);
}

OLED_class::~OLED_class() { close(i2c_fd_); }

bool OLED_class::Border_Show(){
    clearall();
    const uint8_t *charData = oled_frame;

    for (int y = 0; y < OLED_HEIGHT; y++) {
        for (int x_byte = 0; x_byte < OLED_WIDTH / 8; x_byte++) {
            uint8_t byte = charData[y * (OLED_WIDTH / 8) + x_byte];
            for (int bit = 0; bit < 8; bit++) {
                int x = x_byte * 8 + (7 - bit); 
                if (byte & (1 << bit)) {
                    OLED_setPixel(x, y, 1); 
                }
            }
        }
    }

    DrawChar(49, 36, 'C', &Font16);
    DrawChar(114, 40, 'h', &Font12);
    DrawChar(106, 40, 'r', &Font12);
    OLED_updateDisplay();
    return true;
}

int countDigits(int number) {
    if (number == 0) return 1;
    return static_cast<int>(std::floor(std::log10(std::abs(number)))) + 1;
}

static std::string Num_charge(int num){
    std::string result;

    for (int i = 4; i >= 0; --i) {
        result = std::to_string(num % 10) + " " + result;
        num /= 10;
    }
    return result;
}

bool OLED_class::TM_upgrade(int TM){
    std::string TM_value = Num_charge(TM);

    clearRegion(5, 36, &Font16);
    clearRegion(17, 36, &Font16);
    clearRegion(31, 36, &Font16);
    // clearRegion(49, 36, &Font16);
    clearRegion(70, 36, &Font16);
    clearRegion(82, 36, &Font16);
    if (countDigits(TM) == 5){
        DrawChar(5, 36, TM_value[0], &Font16);
        DrawChar(17, 36, TM_value[2], &Font16);
        DrawChar(31, 36, TM_value[4], &Font16);
        DrawChar(70, 36, TM_value[6], &Font16);
        DrawChar(82, 36, TM_value[8], &Font16);
    }else{
        DrawChar(5, 36, '0', &Font16);
        DrawChar(17, 36, TM_value[0], &Font16);
        DrawChar(31, 36, TM_value[2], &Font16);
        DrawChar(70, 36, TM_value[4], &Font16);
        DrawChar(82, 36, TM_value[6], &Font16);
    }

    if (!OLED_updateDisplay()) {
        close(i2c_fd);
        return false;
    }
    return true;
}

bool OLED_class::Date_upgrade(){
    std::string data = GetDate();

    clearRegion(8, 9, &Font12);
    clearRegion(16, 9, &Font12);
    clearRegion(26, 9, &Font12);
    clearRegion(35, 9, &Font12);
    clearRegion(42, 9, &Font12);
    clearRegion(52, 9, &Font12);
    clearRegion(60, 9, &Font12);
    clearRegion(68, 9, &Font12);
    clearRegion(76, 9, &Font12);
    clearRegion(89, 9, &Font12);
    clearRegion(97, 9, &Font12);
    clearRegion(105, 9, &Font12);
    clearRegion(113, 9, &Font12);
    // clearRegion(114, 40, &Font12);
    // clearRegion(106, 40, &Font12);

    DrawChar(8, 9, data[0], &Font12);
    DrawChar(16, 9, data[1], &Font12);
    DrawChar(26, 9, data[2], &Font12);
    DrawChar(35, 9, data[3], &Font12);
    DrawChar(42, 9, data[4], &Font12);
    DrawChar(52, 9, data[5], &Font12);
    DrawChar(60, 9, data[6], &Font12);
    DrawChar(68, 9, data[7], &Font12);
    DrawChar(76, 9, data[8], &Font12);
    DrawChar(89, 9, data[9], &Font12);
    DrawChar(97, 9, data[10], &Font12);
    DrawChar(105, 9, data[11], &Font12);
    DrawChar(113, 9, data[12], &Font12);

    if (!OLED_updateDisplay()) {
        close(i2c_fd);
        return true;
    }
    return true;
}

bool OLED_class::Word_Show(){
    std::string data = GetDate();

    clearRegion(8, 9, &Font12);
    clearRegion(16, 9, &Font12);
    clearRegion(26, 9, &Font12);
    clearRegion(35, 9, &Font12);
    clearRegion(42, 9, &Font12);
    clearRegion(52, 9, &Font12);
    clearRegion(60, 9, &Font12);
    clearRegion(68, 9, &Font12);
    clearRegion(76, 9, &Font12);
    clearRegion(89, 9, &Font12);
    clearRegion(97, 9, &Font12);
    clearRegion(105, 9, &Font12);
    clearRegion(113, 9, &Font12);
    // clearRegion(114, 40, &Font12);
    // clearRegion(106, 40, &Font12);

    DrawChar(8, 9, data[0], &Font12);
    DrawChar(16, 9, data[1], &Font12);
    DrawChar(26, 9, data[2], &Font12);
    DrawChar(35, 9, data[3], &Font12);
    DrawChar(42, 9, data[4], &Font12);
    DrawChar(52, 9, data[5], &Font12);
    DrawChar(60, 9, data[6], &Font12);
    DrawChar(68, 9, data[7], &Font12);
    DrawChar(76, 9, data[8], &Font12);
    DrawChar(89, 9, data[9], &Font12);
    DrawChar(97, 9, data[10], &Font12);
    DrawChar(105, 9, data[11], &Font12);
    DrawChar(113, 9, data[12], &Font12);
    // DrawChar(114, 40, 'h', &Font12);
    // DrawChar(106, 40, 'r', &Font12);

    if (!OLED_updateDisplay()) {
        close(i2c_fd);
        return true;
    }
    return true;
}

bool OLED_class::Warning_Show(){
    clearall();
    const uint8_t *charData = warningPattern;

    for (int y = 0; y < OLED_HEIGHT; y++) {
        for (int x_byte = 0; x_byte < OLED_WIDTH / 8; x_byte++) {
            uint8_t byte = charData[y * (OLED_WIDTH / 8) + x_byte];
            for (int bit = 0; bit < 8; bit++) {
                int x = x_byte * 8 + (7 - bit);  
                if (byte & (1 << bit)) {
                    OLED_setPixel(x, y, 1);
                }
            }
        }
    }
    OLED_updateDisplay();
    return true;
}

void OLED_class::OLED_Shootdown(){
    I2C_writeCommand(0xAE);
}