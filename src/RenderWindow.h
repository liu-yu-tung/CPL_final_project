#ifndef RENDERWINDOW_H_INCLUDED
#define RENDERWINDOW_H_INCLUDED

#include<SDL.h>
#include<SDL2/SDL_image.h>

#include"Entity.h"

class RenderWindow
{
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    SDL_Texture* loadTexture(const char* p_filePath);
    void cleanUp();
    void clear();
    void render(Entity& p_entity);
    void renderBackground(SDL_Texture * backGround, int BGwidth, int BGheight);
    void display();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // RENDERWINDOW_H_INCLUDED
