#include "Audio_class.hpp"

Audio_class::Audio_class(uint8_t volume)
    :volume_(volume)
{
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
        return;
    }
    Mix_VolumeMusic(volume_);
}

Audio_class::~Audio_class(){
    Mix_FreeMusic(music_);
    Mix_CloseAudio();
    SDL_Quit();
}

void Audio_class::AudioPlay(std::string Music){
    music_ = Mix_LoadMUS(Music.c_str());
    if (!music_) {
        std::cerr << "Failed to load music: " << Mix_GetError() << std::endl;
        return ;
    }

    Mix_PlayMusic(music_, 1);
    std::cout << "[▶️] No external event, now playing music\n";
}

void Audio_class::AudioStop(){
    Mix_HaltMusic();
}

void Audio_class::SetVol(uint8_t Vol){
    volume_ = Vol;
    Mix_VolumeMusic(volume_);
}