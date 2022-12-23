#include"Buttons.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;
GameState CurrentGameState = GAME_STARTED;

Buttons::Buttons(SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h)
:Entity((SCREEN_WIDTH - 200)/2, (SCREEN_HEIGHT - 200)/2, p_tex)
{
    currentFrame.x = cFrame_x;
    currentFrame.y = cFrame_y;
    currentFrame.w = cFrame_w;
    currentFrame.h = cFrame_h;
    w = 200;
    h = 200;
}

void Buttons::handleEvent( SDL_Event& e )
{
	//If mouse event happened
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{
		//Get mouse position
		int mX, mY;
		SDL_GetMouseState( &mX, &mY );

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if( mX < x )
		{
			inside = false;
		}
		//Mouse is right of the button
		else if( mX > x + w )
		{
			inside = false;
		}
		//Mouse above the button
		else if( mY < y )
		{
			inside = false;
		}
		//Mouse below the button
		else if( mY > y + h )
		{
			inside = false;
		}

		if(inside)
		{
			//Set mouse over sprite
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
                scale(1);
				break;

				case SDL_MOUSEBUTTONDOWN:
				scale(1);
				break;

				case SDL_MOUSEBUTTONUP:
				w = 200;
				h = 200;
				changeState();
				break;
			}
		}
	}
}

void Buttons::changeState()
{
    if(CurrentGameState == GAME_LAUNCHED)
        CurrentGameState = GAME_STARTED;
    if(CurrentGameState == GAME_STARTED)
        CurrentGameState = GAME_OVER;
    if(CurrentGameState == GAME_OVER)
        CurrentGameState = GAME_LAUNCHED;
}

void Buttons::scale(float n)
{
    x -= (n-1)/2*w;
    h -= (n-1)/2*h;
    w *= n;
    h *= n;
}
