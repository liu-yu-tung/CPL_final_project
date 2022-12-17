#include"Timer.h"



#include<iostream>
#include<sstream>
#include<iomanip>

Timer::Timer()
{
    TTF_Init();
    font = TTF_OpenFont("lazy.ttf", 28);
    if(font == NULL) std::cout << "Font = NULL" << TTF_GetError() << std::endl;
    x = 640;
    y = 0;
    currentFrame.x = 0;
    currentFrame.y = 0;
}
Timer::~Timer()
{
    TTF_CloseFont( font );
    font = NULL;
    TTF_Quit();
}

void Timer::loadTimer(RenderWindow & p_window)
{
    update();
    if( tex != NULL )
	{
		SDL_DestroyTexture( tex );
		tex = NULL;
	}
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, timeText.str().c_str(), textColor );
	if( textSurface != NULL )
	{
        tex = SDL_CreateTextureFromSurface( p_window.GetRenderer(), textSurface );
		if( tex == NULL )
		{
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			currentFrame.w = textSurface->w;
            currentFrame.h = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface( textSurface );
	}
	else
	{
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	}
}

void Timer::update()
{
    timeText.str("");
    timeText << ((double)(int)((SDL_GetTicks() - startTime)/100.f))/10.f;
//    std::cout << timeText.str() << std::endl;
}

void Timer::restart()
{
    startTime = SDL_GetTicks();
}



//void Timer::loadFromRenderedText()
//{
//	//Get rid of preexisting texture
//	free();
//
//	//Render text surface
//	SDL_Surface* textSurface = TTF_RenderText_Solid( font, timeText.str().c_str(), textColor );
//	if( textSurface != NULL )
//	{
//		//Create texture from surface pixels
//        mTexture = SDL_CreateTextureFromSurface( gRenderer, textSurface );
//		if( mTexture == NULL )
//		{
//			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
//		}
//		else
//		{
//			//Get image dimensions
//			mWidth = textSurface->w;
//			mHeight = textSurface->h;
//		}
//
//		//Get rid of old surface
//		SDL_FreeSurface( textSurface );
//	}
//	else
//	{
//		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
//	}
//
//
//	//Return success
//}
