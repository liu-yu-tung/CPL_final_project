#include "ball.h"

Ball::Ball() {
    r = 50, dx = 5, dy= 1, x = 0, y = 0, v = 5;
    ddy = 1;
}
Ball::Ball (int _r, int _x, int _y, int _v, int _color) {
    r = _r, x = _x, y = _y, v = _v, color = _color;
    dy = 1;
    ddy = 1;
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
    ddy = 1;
    r = rand() %  100 + 25;
    x = rand() % (1280 - r);
    y = rand() % (720 / 2 - r);
    v = rand() % 15 + 1;
    dy = rand() % 4 + 1;
    color = rand() % 16;
    //std::cout << color << std::endl;
}
void Ball::motion () {
    dy += ddy;
    x += dx; 
    if (x < r) dx = v;
    else if (x >= 1280 - r) dx = -v;
    if (y < r && dy < 0) dy = -dy;
    else if (y >= 720 - r && dy > 0) dy = - dy;
    else y += dy;

    std::cout << "id: " << id << ", (" << x << ", " << y << ")\n";
}
std::mt19937 Ball::seeded_engine() { 
    std::random_device r;
    std::seed_seq seed{r(), r(), r(), r(), r(), r(), r(), r()};
    return std::mt19937(seed);
}
