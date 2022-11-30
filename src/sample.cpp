#include "graphics.h"

class Ball {
public:
    Ball() {
        r = 50, dx = 5, dy= 1, x = 0, y = 0;
        color = GREEN;
        ddy = 2;
    }
    int r, dx, dy, ddy, x, y, color;
    void motion () {
		dy += ddy;
		x += dx; 
        if (x < r) {
            dx = 5;
        }
        if (x >= getmaxx() - r) {
            dx = -5;
        }  
        if (y < r && dy < 0) {
            dy = -dy;
        }
        else if (y >= getmaxy() - r && dy > 0) {
            dy = - dy;
        }
        else {
            y += dy;
        }
    }
};

int main(int argc, char*argv[]){
	//int x = 120, y = 120, dx = 5, dy = 1, ddy = 2, r = 100;
    Ball b; // must be outside the while function
	initwindow(800, 640);	//window size
	while (1){
		if(kbhit()) break;
		cleardevice();
		setcolor(GREEN);
		setfillstyle(SOLID_FILL, BLUE);
		fillellipse(b.x, b.y, b.r, b.r);
        b.motion();
		refresh();
		delay(10);
	}
	closegraph();
}

