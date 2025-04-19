#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#define CHIP_NAME      "gpiochip0"  // 树莓派默认第一个 GPIO 控制器
#define LINE_OFFSET    22            // 接到模块 DO 引脚的 BCM 编号，例如 GPIO4

static int keep_running = 1;

void sigint_handler(int sig)
{
    keep_running = 0;
}

int main(void)
{
    struct gpiod_chip  *chip;
    struct gpiod_line *line;
    int value;

    signal(SIGINT, sigint_handler);

    /* 打开 GPIO 控制器 */
    chip = gpiod_chip_open_by_name(CHIP_NAME);
    if (!chip) {
        perror("打开 " CHIP_NAME " 失败");
        return EXIT_FAILURE;
    }

    /* 获取一条 GPIO 线并配置为输入 */
    line = gpiod_chip_get_line(chip, LINE_OFFSET);
    if (!line) {
        perror("获取 GPIO 线失败");
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    if (gpiod_line_request_input(line, "light-sensor") < 0) {
        perror("请求输入模式失败");
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    printf("按 Ctrl+C 退出，开始读取光照状态...\n");

    /* 主循环：每 200ms 读一次电平 */
    while (keep_running) {
        value = gpiod_line_get_value(line);
        if (value < 0) {
            perror("读取 GPIO 值失败");
            break;
        }

        if (!value)
            printf("◆ 检测到有光 (DO=1)\n");
        else
            printf("◆ 检测到无光 (DO=0)\n");

        usleep(200 * 1000);
    }

    /* 清理 */
    gpiod_line_release(line);
    gpiod_chip_close(chip);
    printf("已退出。\n");
    return EXIT_SUCCESS;
}
