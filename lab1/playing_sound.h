//
// Created by michael on 04.11.23.
//

#ifndef LAB1_PLAYING_SOUND_H
#define LAB1_PLAYING_SOUND_H


#include<iostream>
#include<windows.h>
int main(){
    std::string name;
    std::string a1 = "happy.wav";
    std::string a2 = "apple.wav";

    PlaySound((a1.c_str()),NULL,SND_SYNC);
    PlaySound((a2.c_str()),NULL,SND_SYNC);
    return 0;
}

#endif //LAB1_PLAYING_SOUND_H