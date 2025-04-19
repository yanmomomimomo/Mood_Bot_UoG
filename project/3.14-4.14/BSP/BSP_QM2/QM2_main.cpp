#include <gpiod.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <csignal>
#include <cstdlib>

// 默认参数——根据实际接线修改
#define CHIP_NAME           "gpiochip0"
#define LINE_SMOKE_OFFSET   21   // BCM4 接 QM2 模块 DO
#define LINE_ALARM_OFFSET   17  // BCM17 接报警指示 LED 或蜂鸣器
#define SAMPLE_COUNT        10  // 每次检测采样次数
#define SAMPLE_INTERVAL_MS  50  // 采样间隔（毫秒）
#define THRESHOLD_COUNT     5   // 判定“超标”需要的最低高电平次数

static bool keep_running = true;
void sigint_handler(int) { keep_running = false; }

int main()
{
    signal(SIGINT, sigint_handler);

    // 打开 GPIO 控制器
    gpiod_chip *chip = gpiod_chip_open_by_name(CHIP_NAME);
    if (!chip) {
        std::perror("打开 " CHIP_NAME " 失败");
        return EXIT_FAILURE;
    }

    // 获取烟雾输入线
    gpiod_line *line_smoke = gpiod_chip_get_line(chip, LINE_SMOKE_OFFSET);
    if (!line_smoke) {
        std::perror("获取烟雾检测线失败");
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }
    if (gpiod_line_request_input(line_smoke, "qm2-smoke") < 0) {
        std::perror("请求烟雾检测输入模式失败");
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    // 获取报警输出线
    gpiod_line *line_alarm = gpiod_chip_get_line(chip, LINE_ALARM_OFFSET);
    if (!line_alarm) {
        std::perror("获取报警线失败");
        gpiod_line_release(line_smoke);
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }
    if (gpiod_line_request_output(line_alarm, "qm2-alert", 0) < 0) {
        std::perror("请求报警输出模式失败");
        gpiod_line_release(line_smoke);
        gpiod_chip_close(chip);
        return EXIT_FAILURE;
    }

    std::cout << "按 Ctrl+C 退出，开始烟雾浓度超标检测...\n";

    while (keep_running) {
        int high_count = 0;
        // 多次采样
        for (int i = 0; i < SAMPLE_COUNT; ++i) {
            int v = gpiod_line_get_value(line_smoke);
            if (v < 0) {
                std::perror("读取烟雾检测线值失败");
                keep_running = false;
                break;
            }
            if (v) 
                high_count++;
            std::this_thread::sleep_for(std::chrono::milliseconds(SAMPLE_INTERVAL_MS));
        }
        if (!keep_running) break;

        // 判断是否超标
        if (high_count >= THRESHOLD_COUNT) {
            // DO=1 表示烟雾浓度超出预设阈值
            gpiod_line_set_value(line_alarm, 1);
            std::cout << "‼️ 烟雾超标 (高电平次数：" << high_count << ")\n";
        } else {
            gpiod_line_set_value(line_alarm, 0);
            std::cout << "✔️ 烟雾正常 (高电平次数：" << high_count << ")\n";
        }
    }

    // 清理
    gpiod_line_release(line_alarm);
    gpiod_line_release(line_smoke);
    gpiod_chip_close(chip);
    std::cout << "已退出。\n";
    return EXIT_SUCCESS;
}
