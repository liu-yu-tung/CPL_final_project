#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include<SDL.h>
#include<SDL2/SDL_IMAGE.h>

class Entity
{
public:
    Entity(){}
    Entity(float p_x, float p_y, SDL_Texture* p_tex);
    Entity(float p_x, float p_y, SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h);

    float getX();
    float getY();
    float getW();
    float getH();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    SDL_Rect getCollisionBox();
    void move();

protected:
    float x, y, w, h, vx = 0, vy = 0;
    SDL_Rect currentFrame;
    SDL_Rect CollisionBox;
    SDL_Texture* tex;
};

#endif // ENTITY_H_INCLUDED
