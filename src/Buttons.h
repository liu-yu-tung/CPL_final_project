#ifndef BUTTONS_H_INCLUDED
#define BUTTONS_H_INCLUDED

#include"Entity.h"

enum GameState
{
    GAME_LAUNCHED = 0,
    GAME_STARTED = 1,
    GAME_OVER = 2
};

class Buttons : public Entity
{
public:
    Buttons(SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h);
    void handleEvent(SDL_Event &e);
private:
    void changeState();
    void scale(float n);
};

#endif // BUTTONS_H_INCLUDED
