/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings

#include<SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

#include"RenderWindow.h"
#include"Entity.h"
#include "ball.h"

extern const int SCREEN_WIDTH = 1280;
extern const int SCREEN_HEIGHT = 720;

int main(int argc, char* args[])
{

    if(SDL_Init(SDL_INIT_VIDEO) > 0)
        std::cout << "SDL_Init has failed." << std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_onit has failed." << std::endl;

    RenderWindow window("GAME", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* dot = window.loadTexture("./img/dot.bmp");
    SDL_Texture* BackGround = window.loadTexture("./img/press.bmp");

    Entity entities[3] = {Entity(0, 0, dot),
                          Entity(30, 30, dot),
                          Entity(30, 0, dot)};

    bool gameRunning = true;

    SDL_Event event;

    while(gameRunning){
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT)
                gameRunning = false;
            entities[2].handleEvent(event);
        }
        window.clear();

        entities[2].move();

       window.renderBackground(BackGround, 640, 480);

        for(int i = 0; i < 3; i++){
            window.render(entities[i]);
        }

        window.display();
    }
    window.cleanUp();
    SDL_Quit();
    return 0;
}