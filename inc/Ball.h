#ifndef BALL_H
#define BALL_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

class Ball {
public:
    Ball();
    Ball (int _r, int _x, int _y, int _v, int _color);
    void init(int _screenWidth, int _screenHeight, int _floorHeight);
    void randomGenerator ();
    void motion ();
    int r, dx, dy, ddy, x, y, color, v;
    int id = -1;
private:
    std::mt19937 eng = seeded_engine();
    std::mt19937 seeded_engine();
    int screenWidth; int screenHeight; int floorHeight;
};

#endif