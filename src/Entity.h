#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include<SDL.h>
#include<SDL2/SDL_IMAGE.h>

class Entity
{
public:
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    float getX();
    float getY();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    void handleEvent(SDL_Event &e);
    void move();
private:
    float x, y, vx, vy;
    SDL_Rect currentFrame;
    SDL_Texture* tex;
};

#endif // ENTITY_H_INCLUDED
