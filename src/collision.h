#ifndef _COLLISION_H_
#define _COLLISION_H_

#include <iostream>
#include <SDL.h>
#include <math.h>
#include"ball.h"

bool Collision(Ball& p_ball, SDL_Rect rect){//true means collision
	if(rect.x <= p_ball.GetX() && p_ball.GetX() <= rect.x + rect.w){//球心x重疊
		if(rect.y - p_ball.GetR() <= p_ball.GetY() && p_ball.GetY() <= rect.y + rect.h + p_ball.GetR()){
//                std::cout << "1" << std::endl;
            return true;
		}
	}
	else if(rect.y <= p_ball.GetY() && p_ball.GetY() <= rect.y + rect.h){//y重疊
		if(rect.x - p_ball.GetR() <= p_ball.GetX() && p_ball.GetX() <= rect.x + rect.w + p_ball.GetR()){
//                std::cout << "2" << std::endl;
            return true;
		}
	}
	else if(p_ball.GetX() < rect.x){//ball在左邊
		if(p_ball.GetY() < rect.y){//左上
			if(pow(rect.x - p_ball.GetX(),2) + pow(rect.y - p_ball.GetY(),2) <= pow(p_ball.GetR(),2)){
//                    std::cout << "3" << std::endl;
                return true;//Pythagorean theorem
			}
			else return false;
		}
		else {//左下
			if(pow(rect.x - p_ball.GetX(),2) + pow(p_ball.GetY() - rect.y - rect.h ,2) <= pow(p_ball.GetR(),2)){
//                    std::cout << "4" << std::endl;
                return true;
			}
			else return false;
		}
	}
	else{//ball在右邊
		if(p_ball.GetY() < rect.y){//右上
			if(pow(p_ball.GetX() - rect.x - rect.w ,2) + pow(rect.y - p_ball.GetY(),2) <= pow(p_ball.GetR(),2)){
//                    std::cout << "5" << std::endl;
                return true;
			}
			else return false;
		}
		else{
			if( (pow(p_ball.GetX() - rect.x - rect.w ,2) + pow(p_ball.GetY() - rect.y - rect.h ,2) ) <= pow(p_ball.GetR(),2)){
//                    std::cout << "6" << std::endl;
//                std::cout << (pow(p_ball.GetX() - rect.x - rect.w ,2) + pow(p_ball.GetY() - rect.y - rect.h ,2) ) - pow(p_ball.GetR(),2) << std::endl;
                return true;
			}
			else return false;
		}
	}
	return false;
}

#endif
