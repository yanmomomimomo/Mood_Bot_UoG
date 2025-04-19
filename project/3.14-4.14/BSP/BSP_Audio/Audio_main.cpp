#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <atomic>
#include <csignal>

// 模拟外部中断事件标志（可以从 GPIO 或别的地方设置为 true）
std::atomic<bool> external_event(false);

// Ctrl+C 模拟外部事件终止播放（实际中可以来自 GPIO 或其他线程）
void signalHandler(int) {
    external_event = true;
    std::cout << "[!] External event (Ctrl+C) triggered\n";
}

int main() {
    std::signal(SIGINT, signalHandler);

    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        return 1;
    }

    // === [1] 阻塞等待周期：1秒 ===
    std::cout << "[⏳] Waiting for 1 second for external event...\n";
    for (int i = 0; i < 10; ++i) { // 每100ms检查一次，共1秒
        if (external_event) {
            std::cout << "[🚫] Event detected during wait. Cancelling playback.\n";
            Mix_CloseAudio();
            SDL_Quit();
            return 0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    // === [2] 超时无事件，开始播放音乐 ===
    Mix_Music* music = Mix_LoadMUS("../../../lib/music/happy/test.mp3");
    if (!music) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return 1;
    }

    Mix_PlayMusic(music, 1);
    std::cout << "[▶️] No external event, now playing music\n";

    // === [3] 播放期间，也可以被外部事件打断 ===
    while (Mix_PlayingMusic()) {
        if (external_event) {
            std::cout << "[🛑] External event occurred! Stopping music.\n";
            Mix_HaltMusic(); // 停止音乐
            break;
        }
        SDL_Delay(100);
    }

    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}


//"../../../lib/music/happy/test.mp3"
