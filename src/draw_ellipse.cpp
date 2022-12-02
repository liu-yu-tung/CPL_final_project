#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
void sdl_ellipse(SDL_Renderer* r, int x0, int y0, int radiusX, int radiusY) {
    float pi  = 3.14159265358979323846264338327950288419716939937510;
    float pih = pi / 2.0; 
    const int prec = 27;     
    float theta = 0;     
    int x  = (float)radiusX * cos(theta);    
    int y  = (float)radiusY * sin(theta);    
    int x1 = x;
    int y1 = y;
    float step = pih/(float)prec; 
    for(theta=step;  theta <= pih;  theta+=step) {
        x1 = (float)radiusX * cosf(theta) + 0.5; 
        y1 = (float)radiusY * sinf(theta) + 0.5; 
        if( (x != x1) || (y != y1) ) {
            SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );
            SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );
            SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );
            SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );
        }
        x = x1;
        y = y1;
    }
    if(x!=0) {
        x=0;
        SDL_RenderDrawLine(r, x0 + x, y0 - y,    x0 + x1, y0 - y1 );
        SDL_RenderDrawLine(r, x0 - x, y0 - y,    x0 - x1, y0 - y1 );
        SDL_RenderDrawLine(r, x0 - x, y0 + y,    x0 - x1, y0 + y1 );
        SDL_RenderDrawLine(r, x0 + x, y0 + y,    x0 + x1, y0 + y1 );
    }
}
