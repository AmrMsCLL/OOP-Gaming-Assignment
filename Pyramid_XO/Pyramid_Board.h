//
// Created by ahmad on 12/13/2023.
//

#ifndef BOARD_PYRAMID_BOARD_H
#define BOARD_PYRAMID_BOARD_H
#include "BoardGame_Classes.hpp"


class Pyramid_Board : Board {
public:
    Pyramid_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};


#endif //BOARD_PYRAMID_BOARD_H
