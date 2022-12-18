#include "ball.h"

Ball::Ball() {
    r = 50, dx = 0.01, dy= 0.00001, x = 0, y = 0, v = 0.01;
    ddy = 0.0000001;
}
Ball::Ball (float _r, float _x, float _y, float _v, float _color) {
    r = _r, x = _x, y = _y, v = _v, color = _color;
    dy = 1;
    ddy = 1;
}
void Ball::init(int _screenWidth, int _screenHeight, int _floorHeight,  SDL_Texture* p_tex) {
    screenWidth = _screenWidth, screenHeight = _screenHeight, floorHeight = _floorHeight;
    ballTex = p_tex;
}
void Ball::randomGenerator () {
    /*
    r = std::uniform_int_distribution<>(25,125)(eng);
    x = std::uniform_int_distribution<>(0, getmaxx())(eng);
    y = std::uniform_int_distribution<>(0, getmaxy())(eng);
    v = std::uniform_int_distribution<>(1, 30)(eng);
    dy = std::uniform_int_distribution<>(1, 5)(eng);
    color = std::uniform_int_distribution<>(0, 15)(eng);
    */
    ddy = 0.001;
    r = 1.0*(rand() %  100 + 25);
    //x = 1.01*(rand() % (screenWidth - (int)r));
    x = 1.0*((rand() % 2) * screenWidth);
    if (x == 0) x -= r; else x += r;
    y = 1.01*(rand() % (screenHeight / 2 - (int)r));
    v = 1.01*(rand() % 15 + 1);
    dy = 1.00001*(rand() % 4 + 1);
    dx = 1.00001*(rand() % 4 + 1);
    if (x > 0) dx *= -1; 
    color = 1.0*(rand() % 16);
    //std::cout << color << std::endl;
}
void Ball::motion () {
    dy += ddy;
    x += dx;
    if (x < -r) randomGenerator();
    else if (x >= screenWidth + r) randomGenerator();
    if (y < r && dy < 0) dy = -dy;
    else if (y >= screenHeight - floorHeight - r && dy > 0) dy = - dy;
    else y += dy;
    //std::cout << "id: " << id << ", (" << x << ", " << y << ")\n";
}
std::mt19937 Ball::seeded_engine() {
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    return std::mt19937(seed);
}

float Ball::GetX() {
    return x;
}
float Ball::GetY() {
    return y;
}
float Ball::GetR() {
    return r;
}
SDL_Texture* Ball::GetTex() {
    return ballTex;
}
