#include"Timer.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

Timer::Timer()
{
    TTF_Init();
	best = 0.0;
    font = TTF_OpenFont("lazy.ttf", 100);
    if(font == NULL) std::cout << "Font = NULL" << TTF_GetError() << std::endl;
    x = 600;
    y = 0;
    currentFrame.x = 0;
    currentFrame.y = 0;
	std::string ch;
	myfile.open("myfile.in", std::ios::in);
	if (!myfile) {
		std::cout << "No such file!\n";
	}
	else {
		std::cout << "File open successfully!\n";
		myfile >> ch;
		std::cout << ch << "\n";
		best = std::stod(ch);
	}
	myfile.close();
	std::cout << "File closed!\n";

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
	w = currentFrame.w;
	h = currentFrame.h;
	x = ( SCREEN_WIDTH - w )/2;
}

void Timer::update()
{
    timeText.str("");
    record_thisRound =  ((double)(int)((SDL_GetTicks() - startTime)/100.f))/10.f;
    timeText << record_thisRound;
//    std::cout << timeText.str() << std::endl;
}

void Timer::reset()
{
     y = 0;
    startTime = SDL_GetTicks();
}

void Timer::showRecord(RenderWindow & p_window)
{
    if(best < record_thisRound){
        best = record_thisRound;
    }
    timeText.str("");
    timeText << "Best:  " << best << "  ";
    timeText << "Your:  " << record_thisRound;

	myfile.open("myfile.in", std::ios::out);
	if (!myfile) {
	}
	else {
		myfile << best;
		myfile.close();
	}

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
    y = 200;
    w = currentFrame.w;
    h = currentFrame.h;
    x = ( SCREEN_WIDTH - w )/2;
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
