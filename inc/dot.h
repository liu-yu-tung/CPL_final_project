#ifndef _DOT_H_
#define _DOT_H_

#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Dot {
public:
	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;
	static const int DOT_VEL = 10;
	Dot();
	void handleEvent( SDL_Event& e );
	void move( SDL_Rect& wall );
	void render();
private:
	int mPosX, mPosY;
	int mVelX, mVelY;
	SDL_Rect mCollider;
};

#endif