#include"Entity.h"
#include<SDL.h>
#include<SDL2/SDL_IMAGE.h>

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 20;
    currentFrame.h = 20;
}

float Entity::getX()
{
    return x;
}

float Entity::getY()
{
    return y;
}

SDL_Texture* Entity::getTex()
{
    return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;
}

void Entity::handleEvent(SDL_Event &e)
{
    //If a key was pressed
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: vy -= 1; break;
            case SDLK_DOWN: vy += 1; break;
            case SDLK_LEFT: vx -= 1; break;
            case SDLK_RIGHT: vx += 1; break;
        }
    }
    //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: vy += 1; break;
            case SDLK_DOWN: vy -= 1; break;
            case SDLK_LEFT: vx += 1; break;
            case SDLK_RIGHT: vx -= 1; break;
        }
    }
}

void Entity::move()
{
    x += vx;
    y += vy;
}
