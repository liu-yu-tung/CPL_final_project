#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include"Entity.h"


class Player : public Entity
{
public:
    Player(float p_x, float p_y, SDL_Texture* p_tex, float cFrame_x, float cFrame_y, float cFrame_w, float cFrame_h);
    void handleEvent(SDL_Event &e);
    void animation();
private:
    float ax = 0.5, ay = 3;
};


#endif // PLAYER_H_INCLUDED
