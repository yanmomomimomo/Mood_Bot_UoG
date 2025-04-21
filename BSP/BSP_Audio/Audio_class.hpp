#ifndef __AUDIO_CLASS_HPP
#define __AUDIO_CLASS_HPP

#include "Audio.hpp"

class Audio_class{
    public:
        Audio_class(uint8_t volume);
        ~Audio_class();

        void AudioPlay(std::string Music);
        void SetVol(uint8_t Vol);
        void AudioStop();
    private:
        Mix_Music* music_ {nullptr};
        uint8_t volume_;
};
#endif // __AUDIO_CLASS_HPP