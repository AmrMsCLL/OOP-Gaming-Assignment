#ifndef PYRAMID_XO_AI_PLAYER_H
#define PYRAMID_XO_AI_PLAYER_H
#include "new_player.h"
#include "Pyramid_Board.h"

class AI_player : public new_player {
protected:
    Pyramid_Board* b;
public:
    AI_player(Pyramid_Board* bo, char s);
    void get_move(int& x, int& y);
    friend int minimax(Pyramid_Board* b, int d, bool isMaximizing);
};


#endif //PYRAMID_XO_AI_PLAYER_H
