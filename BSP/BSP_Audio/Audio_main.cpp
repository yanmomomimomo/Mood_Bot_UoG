#include "Audio_class.hpp"

int main() {
    
    SYS_Config();

    Audio_class Audio1(50);
    Audio1.SetVol(80);
    Audio1.AudioPlay(happy_music);
    
    while(true){}
    return 0;
}


//"../../../lib/music/happy/test.mp3"
