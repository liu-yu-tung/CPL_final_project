#include"Player.h"
#include<iostream>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
const int FLOOR_HEIGHT = 75;

Player::Player(float p_x, float p_y, SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h)
:Entity(p_x, p_y, p_tex)
{
    currentFrame.x = cFrame_x;
    currentFrame.y = cFrame_y;
    currentFrame.w = cFrame_w;
    currentFrame.h = cFrame_h;
    w = 100;
    h = 100;
    CollisionBox.x = x + 0.3*w;
    CollisionBox.y = y + 0.3*h;
    CollisionBox.w = 0.4*w;
    CollisionBox.h = 0.4*h;
}

void Player::handleEvent(SDL_Event &e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: vy -= ay; break;
            case SDLK_DOWN: vy += ay; break;
            case SDLK_LEFT: vx -= ax; break;
            case SDLK_RIGHT: vx += ax; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: vy += 0; break;
            case SDLK_DOWN: vy -= 0; break;
            case SDLK_LEFT: vx += ax; break;
            case SDLK_RIGHT: vx -= ax; break;
        }
    }
}

void Player::animation()
{
    static int frameRate = 0, frameCount = 0;
    if(vx != 0){
            if(vx > 0){
                currentFrame.y = 600;
            }
            else{
                currentFrame.y = 400;
            }
        if(frameRate % 50 == 0){
            currentFrame.x += currentFrame.w;
            if(frameCount == 4){
                currentFrame. x = 0;
                frameCount = 0;
            }
            frameCount++;
        }
        frameRate++;
    }
    else{
        currentFrame.x = 0;
        currentFrame.y = 0;
    }
}

void Player::reset()
{
    x = 590;
    y = SCREEN_HEIGHT-FLOOR_HEIGHT-80;
    vx = 0;
    vy = 0;
    currentFrame.x = 0;
    currentFrame.y = 0;
}
