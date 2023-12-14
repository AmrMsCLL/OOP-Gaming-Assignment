//
// Created by ahmad on 12/14/2023.
//

#ifndef BOARD_NEW_RANDOM_H
#define BOARD_NEW_RANDOM_H
#include "new_player.h"
#include <iostream>
using namespace std;


class new_random: public new_player {
    protected:
        int dimension;
    public:
        // Take a symbol and pass it to parent
        new_random (char symbol, int dimension);
        // Generate a random move
        void get_move(int& x, int& y);

};


#endif //BOARD_NEW_RANDOM_H
