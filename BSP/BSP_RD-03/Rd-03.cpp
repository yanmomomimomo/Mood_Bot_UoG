#include "Rd-03_class.hpp"

static int open_serial(const char *dev) {
    int fd = open(dev, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        fprintf(stderr, "打开串口 %s 失败: %s\n", dev, strerror(errno));
        return -1;
    }
    struct termios tty;
    tcgetattr(fd, &tty);
    cfmakeraw(&tty);
    cfsetispeed(&tty, BAUD_RATE);
    cfsetospeed(&tty, BAUD_RATE);
    tty.c_cflag |= CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &tty);
    return fd;
}

static void enter_cmd_mode(int fd) {
    const uint8_t frame[] = {
        0xFD,0xFC,0xFB,0xFA,   // HEADER
        0x04,0x00,             // LEN = 4 bytes payload
        0xFF,0x00,0x01,0x00,   // CMD = 0x00FF, then index/version
        0x04,0x03,0x02,0x01    // TAIL
    };
    write(fd, frame, sizeof(frame));
    usleep(100000);
}

static int set_param(int fd, uint16_t param_id, uint16_t value) {
    uint8_t frame[18];
    // HEADER
    frame[0]=0xFD; frame[1]=0xFC; frame[2]=0xFB; frame[3]=0xFA;
    // LEN = 8 (CMD2 + ParamID2 + Value4)
    frame[4]=0x08; frame[5]=0x00;
    // CMD = 0x0007 
    frame[6]=0x07; frame[7]=0x00;
    // ParamID 小端
    frame[8] = (param_id & 0xFF);
    frame[9] = (param_id >> 8);
    // Value 
    frame[10] = (value & 0xFF);
    frame[11] = (value >> 8);
    frame[12] = 0x00;
    frame[13] = 0x00;
    // TAIL
    frame[14]=0x04; frame[15]=0x03; frame[16]=0x02; frame[17]=0x01;
    if (write(fd, frame, sizeof(frame)) != sizeof(frame)) {
        perror("send_param");
        return -1;
    }
    usleep(100000);
    return 0;
}

static void exit_cmd_mode(int fd) {
    const uint8_t frame[] = {
        0xFD,0xFC,0xFB,0xFA,   // HEADER
        0x02,0x00,             // LEN = 2 bytes payload
        0xFE,0x00,             // CMD = 0x00FE
        0x04,0x03,0x02,0x01    // TAIL
    };
    write(fd, frame, sizeof(frame));
    usleep(100000);
}

RD_class::RD_class(uint8_t offset, const std::string &consumer)
    :chip_(chip0), offset_(offset), consumer_(consumer)
{
    int ser = open_serial(SERIAL_DEV);
    if (ser < 0) return;

    tcflush(ser, TCIOFLUSH);

    enter_cmd_mode(ser);
    if ( set_param(ser, 0x0001, min_dist_cm) < 0 ||
         set_param(ser, 0x0002, max_dist_cm) < 0 ||
         set_param(ser, 0x0004, delay_s)     < 0 ) {
        close(ser);
        return;
    }
    exit_cmd_mode(ser);

    line_ = gpiod_chip_get_line(chip0, offset_);
    if (!line_) {
        return;
    }
    if (gpiod_line_request_input(line_, consumer_.c_str())) {
        return ;
    }
}

RD_class::~RD_class(){}

int RD_class::GetValue(){
    int high_count = 0;
    for(int i= 0; i< 5;i++){
        int v = gpiod_line_get_value(line_);
        if (v < 0) {
            perror("gpiod_line_get_value");
            return -1;
        }
        if (v > 0){high_count++;}
    }
    if (high_count <= 3){
        return NO_HUM;
    }else{
        return HUM;
    }
}