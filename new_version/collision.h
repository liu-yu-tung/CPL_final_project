#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <iostream>
#include <SDL.h>
#include <math.h>

bool Collision(int ball_x, int ball_y, int ball_r, SDL_Rect rect){//true means collision
	//std::cout << ball_x << ", " << ball_y << ", " << ball_r << "\n";
	//std::cout << rect.x << ", " << rect.y << ", " << rect.h << ", " << rect.w << "\n";
	if((rect.x <= ball_x) && (ball_x <= (rect.x + rect.w))){ // x value overlape 
		if(rect.y - ball_r <= ball_y && ball_y <= rect.y + rect.h + ball_r) {
			//std::cout << ball_x << ", " << ball_y << ", " << ball_r << "\n";
			//std::cout << rect.x << ", " << rect.y << ", " << rect.h << ", " << rect.w << "\n";
			std::cout << "x value overlape\n";
			return true;
		}
	}
	else if(rect.y <= ball_y && ball_y <= rect.y + rect.h){ // y value overlape
		if(rect.x - ball_r <= ball_x && ball_x <= rect.x + rect.w + ball_r) {
			std::cout << "y value overlape\n";
			return true;
		}
	}
	else if(ball_x < rect.x){ //ball at the left side
		if(ball_y < rect.y){// up left
			if(pow(rect.x - ball_x,2) + pow(rect.y - ball_y,2) <= pow(ball_r,2)) {
				std::cout << "up left\n";
				return true;//Pythagorean theorem
			}
			else return false;
		}
		else {// down left
			if(pow(rect.x - ball_x,2) + pow(ball_y - rect.y - rect.h ,2) <= pow(ball_r,2)) {
				std::cout << "down left\n";
				return true;
			}
			else return false;
		}
	}
	else{// ball at the right side
		if(ball_y < rect.y){// up right
			if(pow(ball_x - rect.x - rect.w ,2) + pow(rect.y - ball_y,2) <= pow(ball_r,2)) {
				std::cout << "up right\n";
				return true;
			}
			else return false;
		}
		else{
			if(pow(ball_x - rect.x - rect.w ,2) + pow(ball_y - rect.y - rect.h ,2) <= pow(ball_r,2)) {
				std::cout << "down right\n";
				return true;
			}
			else return false;
		}
	}
	return false;
}

#endif
