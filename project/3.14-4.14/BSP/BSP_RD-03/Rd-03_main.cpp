/**
 * rd03_board_uart.c
 *
 * 树莓派板载 UART + libgpiod + AiThink RD‑03
 * 支持下发最小/最大探测距离与目标消失延迟，并通过 OT2 GPIO 每秒打印“有人/无人”。
 */

 #include <gpiod.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <unistd.h>
 #include <fcntl.h>
 #include <termios.h>
 #include <string.h>
 #include <errno.h>
 
 // —— 硬件 & 参数配置 ——
 
 // GPIO chip 与 OT2 引脚（BCM 编号）
 #define GPIO_CHIP   "/dev/gpiochip0"
 #define OT2_LINE    17            // OT2 接到 BCM17
 
 // 串口设备与波特率
 #define SERIAL_DEV  "/dev/serial0"
 #define BAUD_RATE    B115200
 
 // 探测参数（可按需修改后重新编译）
 static const uint16_t min_dist_cm = 50;   // 最小探测距离 (cm)
 static const uint16_t max_dist_cm = 300;  // 最大探测距离 (cm)
 static const uint16_t delay_s     = 5;    // 目标消失延迟 (s)
 
 // 封装：打开并配置串口，raw 模式 115200 8N1
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
 
 // 进入命令模式
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
 
 // 退出命令模式
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
 
 // 配置单个参数：param_id & value（16-bit 小端），协议要求 LEN=8，VALUE 用 4 字节 LE
 static int set_param(int fd, uint16_t param_id, uint16_t value) {
     uint8_t frame[18];
     // HEADER
     frame[0]=0xFD; frame[1]=0xFC; frame[2]=0xFB; frame[3]=0xFA;
     // LEN = 8 (CMD2 + ParamID2 + Value4)
     frame[4]=0x08; frame[5]=0x00;
     // CMD = 0x0007 (参数写入)
     frame[6]=0x07; frame[7]=0x00;
     // ParamID 小端
     frame[8] = (param_id & 0xFF);
     frame[9] = (param_id >> 8);
     // Value (4 字节 小端)
     frame[10] = (value & 0xFF);
     frame[11] = (value >> 8);
     frame[12] = 0x00;
     frame[13] = 0x00;
     // TAIL
     frame[14]=0x04; frame[15]=0x03; frame[16]=0x02; frame[17]=0x01;
     // 发送
     if (write(fd, frame, sizeof(frame)) != sizeof(frame)) {
         perror("send_param");
         return -1;
     }
     usleep(100000);
     return 0;
 }
 
 int main(void) {
     // —— 1. 串口初始化 & 参数下发 ——
     int ser = open_serial(SERIAL_DEV);
     if (ser < 0) return 1;
     printf("串口 %s 打开成功，开始配置参数...\n", SERIAL_DEV);
 
     // 清空残留数据
     tcflush(ser, TCIOFLUSH);
 
     // 进入命令模式并配置
     enter_cmd_mode(ser);
     if ( set_param(ser, 0x0001, min_dist_cm) < 0 ||
          set_param(ser, 0x0002, max_dist_cm) < 0 ||
          set_param(ser, 0x0004, delay_s)     < 0 ) {
         fprintf(stderr, "参数配置失败\n");
         close(ser);
         return 1;
     }
     exit_cmd_mode(ser);
     printf("参数已下发：min=%dcm, max=%dcm, delay=%ds\n",
            min_dist_cm, max_dist_cm, delay_s);
 
     // —— 2. GPIO 初始化 & OT2 检测 ——
     struct gpiod_chip *chip = gpiod_chip_open(GPIO_CHIP);
     if (!chip) {
         perror("gpiod_chip_open");
         close(ser);
         return 1;
     }
     struct gpiod_line *line = gpiod_chip_get_line(chip, OT2_LINE);
     if (!line) {
         perror("gpiod_chip_get_line");
         gpiod_chip_close(chip);
         close(ser);
         return 1;
     }
     if (gpiod_line_request_input(line, "rd03_ot2")) {
         perror("gpiod_line_request_input");
         gpiod_chip_close(chip);
         close(ser);
         return 1;
     }
     printf("GPIO%d (OT2) 已就绪，开始每秒检测...\n", OT2_LINE);
 
     // —— 3. 主循环：读取 OT2 输出 并打印 ——
     while (1) {
         int v = gpiod_line_get_value(line);
         if (v < 0) {
             perror("gpiod_line_get_value");
             break;
         }
         printf("%s\n", v ? "有人" : "无人");
         sleep(1);
     }
 
     // 清理
     gpiod_line_release(line);
     gpiod_chip_close(chip);
     close(ser);
     return 0;
 }
 