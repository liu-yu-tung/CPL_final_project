#include"Player.h"

Player::Player(float p_x, float p_y, SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h)
:Entity(p_x, p_y, p_tex)
{
    currentFrame.x = cFrame_x;
    currentFrame.y = cFrame_y;
    currentFrame.w = cFrame_w;
    currentFrame.h = cFrame_h;
}

void Player::handleEvent(SDL_Event &e)
{
	if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: vy -= ay; break;
            case SDLK_DOWN: vy += ay; break;
            case SDLK_LEFT: vx -= ax; currentFrame.y = 400; break;
            case SDLK_RIGHT: vx += ax; currentFrame.y = 600; break;
        }
    }
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym )
        {
//            case SDLK_UP: vy += ay; break;
//            case SDLK_DOWN: vy -= ay; break;
            case SDLK_LEFT: vx += ax; break;
            case SDLK_RIGHT: vx -= ax; break;
        }
    }
}

void Player::animation()
{
    static int frameRate = 0, frameCount = 0;
    if(frameRate % 100 == 0){
        currentFrame.x += currentFrame.w;
        if(frameCount == 4){
            currentFrame. x = 0;
            frameCount = 0;
        }
        frameCount++;
    }
    frameRate++;
}
