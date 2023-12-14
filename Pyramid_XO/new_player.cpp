//
// Created by ahmad on 12/13/2023.
//

#include "new_player.h"
#include <iostream>
using namespace std;
new_player::new_player(char symbol)
{
    this->symbol = symbol;
}

new_player::new_player(int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void new_player::get_move(int &x, int &y)
{
    x = 0, y = 0;
    cout << "\nPlease enter your move x (0 to 2), y (0 to 4) separated by spaces: ";
    cin >> x >> y;
        while((x == 0 && (y == 0 || y == 1|| y == 3|| y == 4)) || (x == 1 && (y == 0 || y == 4))) {
            cout << "\nPlease enter your move x (0 to 2), y (0 to 4) separated by spaces!!!: ";
            cin >> x >> y;
        }
}

string new_player::to_string()
{
    return "Player: " + name;
}

char new_player::get_symbol()
{
    return symbol;
}