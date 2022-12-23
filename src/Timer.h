#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>

#include"SDL2/SDL_ttf.h"
#include"Entity.h"
#include"RenderWindow.h"


class Timer :public Entity
{
public:
    Timer();
    ~Timer();
    void reset();
    void loadTimer(RenderWindow & p_window);
    void showRecord(RenderWindow & p_window);

private:
    void update();
    TTF_Font* font = NULL;
    SDL_Color textColor = { 0, 0, 0, 255 };
    Uint32 startTime = 0;
    float record_thisRound = 0;
    std::stringstream timeText;
};

#endif // TIMER_H_INCLUDED
