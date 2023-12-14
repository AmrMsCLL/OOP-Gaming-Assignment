//
// Created by ahmad on 12/13/2023.
//

#ifndef BOARD_NEW_PLAYER_H
#define BOARD_NEW_PLAYER_H
#include <iostream>
using namespace std;

class new_player {
protected:
    string name;
    char symbol;
public:
    new_player (char symbol);
    new_player (int order, char symbol);

    virtual void get_move(int& x, int& y);

    string to_string();

    char get_symbol();
};


#endif //BOARD_NEW_PLAYER_H
