#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include"RenderWindow.h"
#include"Entity.h"


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
//    SDL_Surface* tempSurface = IMG_Load(p_filePath);
//
//    SDL_SetColorKey( tempSurface, SDL_TRUE, SDL_MapRGB( tempSurface->format, 0xFF, 0xFF, 0xFF ) );
//
//    texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
//
//    SDL_FreeSurface(tempSurface);
    texture = IMG_LoadTexture(renderer, p_filePath);
    if(texture == NULL)
        std::cout << "Failed to load texture." << std::endl;
    return texture;
}

SDL_Renderer* RenderWindow::GetRenderer()
{
    return renderer;
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
    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = p_entity.getX();
    dst.y = p_entity.getY();
    dst.w = p_entity.getCurrentFrame().w;
    dst.h = p_entity.getCurrentFrame().h;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
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
