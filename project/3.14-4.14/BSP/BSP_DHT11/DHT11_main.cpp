#include <gpiod.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <signal.h>
#include <time.h>

// 可调参数：
// RESPONSE_TIMEOUT_MS: 事件等待超时阈值，范围 1-10 ms
// LOGIC_THRESHOLD_US: 判断 0/1 的高脉冲阈值，范围 40-60 µs
// MAX_EDGES: 最多捕获边沿数，需>=66
#define CHIP_NAME           "gpiochip0"
#define DHT_PIN             4
#define RESPONSE_TIMEOUT_MS 7      // ms
#define LOGIC_THRESHOLD_US  56     // µs
#define MAX_EDGES           82     // 应答(2)+数据位(32)*2=66

static volatile int keep_running = 1;
static void int_handler(int signo) {
    (void)signo;
    keep_running = 0;
}

static void delay_ms(int ms) { usleep(ms * 1000); }
static void delay_us(int us) { usleep(us); }

// 简化读取 DHT11：解析湿度和温度的整数+一位小数
int read_dht11(struct gpiod_line *line, float *humidity, float *temperature) {
    struct gpiod_line_event evt;
    struct timespec ts[MAX_EDGES];
    int count = 0;

    // 1. 启动信号
    gpiod_line_request_output(line, "dht11", 0);
    gpiod_line_set_value(line, 0);
    delay_ms(20);
    gpiod_line_set_value(line, 1);
    delay_us(30);
    gpiod_line_release(line);

    // 2. 捕获事件
    if (gpiod_line_request_both_edges_events(line, "dht11") != 0) {
        perror("请求事件失败");
        return -1;
    }
    struct timespec timeout = { .tv_sec = 0,
                                .tv_nsec = RESPONSE_TIMEOUT_MS * 1000000 };
    while (count < MAX_EDGES) {
        int rv = gpiod_line_event_wait(line, &timeout);
        if (rv <= 0) break;
        if (gpiod_line_event_read(line, &evt) == 0) ts[count++] = evt.ts;
    }
    gpiod_line_release(line);
    if (count < 66) return -1;

    // 3. 解析湿度整数和小数(8+8 bits)
    uint8_t h_int = 0, h_dec = 0;
    for (int b = 0; b < 8; b++) {
        int idx = 2 + b*2 + 1;
        long dt = (ts[idx].tv_sec - ts[idx-1].tv_sec)*1000000 + (ts[idx].tv_nsec - ts[idx-1].tv_nsec)/1000;
        h_int = (h_int << 1) | (dt > LOGIC_THRESHOLD_US);
    }
    for (int b = 8; b < 16; b++) {
        int idx = 2 + b*2 + 1;
        long dt = (ts[idx].tv_sec - ts[idx-1].tv_sec)*1000000 + (ts[idx].tv_nsec - ts[idx-1].tv_nsec)/1000;
        h_dec = (h_dec << 1) | (dt > LOGIC_THRESHOLD_US);
    }
    // 4. 解析温度整数和小数(8+8 bits)
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

    *humidity    = h_int + h_dec * 0.1f;
    *temperature = t_int + t_dec * 0.1f;
    return 0;
}

int main(void) {
    signal(SIGINT, int_handler);
    struct gpiod_chip *chip = gpiod_chip_open_by_name(CHIP_NAME);
    if (!chip) { perror("打开GPIO芯片失败"); return 1; }
    struct gpiod_line *line = gpiod_chip_get_line(chip, DHT_PIN);
    if (!line) { perror("获取GPIO线失败"); gpiod_chip_close(chip); return 1; }

    printf("按 Ctrl+C 退出\n");
    while (keep_running) {
        float hum=0, temp=0;
        if (read_dht11(line, &hum, &temp) == 0) {
            // 打印带一位小数
            printf("温度: %.1f°C, 湿度: %.1f%%\n", temp/20, hum/5);
        } else {
            fprintf(stderr, "读取失败\n");
        }
        sleep(2);
    }
    gpiod_chip_close(chip);
    printf("程序已退出\n");
    return 0;
}
