#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <iostream>
#include <SDL.h>
#include <math.h>

bool Collision(int ball_x, int ball_y, int ball_r, SDL_Rect rect){//true means collision

	/*
	if(rect.x <= ball_x && ball_x <= rect.x + rect.w){//�y��x���| 
		if(rect.y - ball_r <= ball_y && ball_y <= rect.y + rect.h + ball_r) return true;
	}
	else if(rect.y <= ball_y && ball_y <= rect.y + rect.h){//y���| 
		if(rect.x - ball_r <= ball_x && ball_x <= rect.x + rect.w + ball_r) return true;
	}
	else if(ball_x < rect.x){//ball�b���� 
		if(ball_y < rect.y){//���W
			if(pow(rect.x - ball_x,2) + pow(rect.y - ball_y,2) <= pow(ball_r,2)) return true;//Pythagorean theorem
			else return false;
		}
		else {//���U
			if(pow(rect.x - ball_x,2) + pow(ball_y - rect.y - rect.h ,2) <= pow(ball_r,2)) return true;
			else return false;
		}
	}
	else{//ball�b�k��
		if(ball_y < rect.y){//�k�W
			if(pow(ball_x - rect.x - rect.w ,2) + pow(rect.y - ball_y,2) <= pow(ball_r,2)) return true;
			else return false;
		}
		else{
			if(pow(ball_x - rect.x - rect.w ,2) + pow(ball_y - rect.y - rect.h ,2) <= pow(ball_r,2)) return true;
			else return false;
		}
	}
	*/
}

#endif
