#include "ball.h"

int main(int argc, char*argv[]){
    /*==============
        create object outside of the while loop
    ================*/
    srand(time(0));
   // Ball b; 
   // Ball c(100, 0, 100, 3, YELLOW);
    Ball *balls = new Ball[10];
    for (int i=0; i<10; i++) {
        balls[i].randomGenerator();
        balls[i].id = i;
    }
	initwindow(1440, 800);	//window size
	while (1){
		if(kbhit()) break;
		cleardevice();
		//setcolor(GREEN);
        for (int i=0; i<10; i++) {
            setfillstyle(SOLID_FILL, balls[i].color);
            fillellipse(balls[i].x, balls[i].y, balls[i].r, balls[i].r);
            balls[i].motion();
        }
		refresh();
		delay(25); 
	}
    delete balls;
	closegraph();
}

