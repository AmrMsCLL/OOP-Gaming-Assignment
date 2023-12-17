#include <iostream>
#include "Classes_header.h"
using namespace std;

XO5_RandomPlayer::XO5_RandomPlayer (char symbol, int dimension):XO5_Player(symbol)
{
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}
void XO5_RandomPlayer::get_move (int& x, int& y) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
