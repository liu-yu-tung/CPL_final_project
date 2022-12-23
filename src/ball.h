#ifndef BALL_H
#define BALL_H

#include<SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

class Ball {
public:
    Ball();
    Ball (float _r, float _x, float _y, float _v, float _color);
    void init(int _screenWidth, int _screenHeight, int _floorHeight, SDL_Texture* p_tex);
    void randomGenerator ();
    void motion ();
    float GetX();
    float GetY();
    float GetR();
    SDL_Texture* GetTex();
    int id = -1;
    double angle = 0;
private:
    float r, dx, dy, ddy, x, y, color, v;
    std::mt19937 eng = seeded_engine();
    std::mt19937 seeded_engine();
    int screenWidth; int screenHeight; int floorHeight;
    SDL_Texture* ballTex;
};

#endif
