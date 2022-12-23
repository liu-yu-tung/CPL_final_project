#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include"RenderWindow.h"
#include"Entity.h"
#include"ball.h"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL){
        std::cout << "Window failed to intialize." << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
    SDL_Texture* texture = NULL;
    SDL_Surface* tempSurface = IMG_Load(p_filePath);

    SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 254, 254, 254 ) );

    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);

    SDL_FreeSurface(tempSurface);
//    texture = IMG_LoadTexture(renderer, p_filePath);
    if(texture == NULL)
        std::cout << "Failed to load texture." << std::endl;
    return texture;
}


void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
    SDL_Rect* src = new SDL_Rect;
    src->x = p_entity.getCurrentFrame().x;
    src->y = p_entity.getCurrentFrame().y;
    src->w = p_entity.getCurrentFrame().w;
    src->h = p_entity.getCurrentFrame().h;

    SDL_Rect* dst = new SDL_Rect;
    dst->x = p_entity.getX();
    dst->y = p_entity.getY();
    dst->w = p_entity.getW();
    dst->h = p_entity.getH();

    SDL_RenderCopy(renderer, p_entity.getTex(), src, dst);

    delete[] src;
    delete[] dst;
}

void RenderWindow::render(Ball& p_ball)
{
    SDL_Rect* src = new SDL_Rect;
    src->x = 0;
    src->y = 0;
    src->w = 380;
    src->h = 380;

    SDL_Rect* dst = new SDL_Rect;
    dst->x = p_ball.GetX() - p_ball.GetR();
    dst->y = p_ball.GetY() - p_ball.GetR();
    dst->w = 2*p_ball.GetR();
    dst->h = 2*p_ball.GetR();

    p_ball.angle += 0.5;

    SDL_Point* center = new SDL_Point;
    center->x = p_ball.GetR();
    center->y = p_ball.GetR();

//    SDL_RenderCopy(renderer, p_ball.GetTex(), src, dst);
    SDL_RenderCopyEx(renderer, p_ball.GetTex(), src, dst, p_ball.angle, center, SDL_FLIP_NONE);
    delete[] src;
    delete[] dst;
    delete[] center;
}

void RenderWindow::renderBackground(SDL_Texture * backGround, int BGwidth, int BGheight)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = BGwidth;
    src.h = BGheight;

    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = SCREEN_WIDTH;
    dst.h = SCREEN_HEIGHT;

    SDL_RenderCopy(renderer, backGround, &src, &dst);
}


void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderWindow::GetRenderer()
{
    return renderer;
}
