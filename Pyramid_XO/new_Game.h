//
// Created by ahmad on 12/13/2023.
//

#ifndef BOARD_NEW_GAME_H
#define BOARD_NEW_GAME_H
#include "Pyramid_Board.h"
#include "new_player.h"

class new_Game {
private:
    Pyramid_Board* boardPtr;
    new_player* players[2];
public:
    new_Game(Pyramid_Board*bPtr, new_player* playerPtr[2]);
    void run();
};


#endif //BOARD_NEW_GAME_H
