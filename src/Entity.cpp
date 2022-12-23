#include"Entity.h"
#include<SDL.h>
#include<SDL2/SDL_IMAGE.h>
#include<iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FLOOR_HEIGHT = 75;

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 20;
    currentFrame.h = 20;
}

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h)
:x(p_x), y(p_y), tex(p_tex)
{
    currentFrame.x = cFrame_x;
    currentFrame.y = cFrame_y;
    currentFrame.w = cFrame_w;
    currentFrame.h = cFrame_h;
    w = cFrame_w;
    h = cFrame_h;
}


float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

float Entity::getW()
{
    return w;
}

float Entity::getH()
{
    return h;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

SDL_Rect Entity::getCollisionBox()
{
    return CollisionBox;
}

void Entity::move()
{
    vy += 0.01;
    x += vx;
    y += vy;
    if( ( x < 0 ) || ( x + w > SCREEN_WIDTH ))
    {
        x -= vx;
    }
        if( ( y < 0 ) || ( y + h > SCREEN_HEIGHT-FLOOR_HEIGHT +20 ))
    {
        y -= vy;
        vy = 0;
//        std::cout << y+h - SCREEN_HEIGHT+FLOOR_HEIGHT+100;
    }
    CollisionBox.x = x + 0.3*CollisionBox.w;
    CollisionBox.y = y + 0.3*CollisionBox.h;
}
