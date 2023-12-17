#include <bits/stdc++.h>
#include "Classes_Header.h"
using namespace std;

Pyramid_RandomPlayer::Pyramid_RandomPlayer(char symbol, int dimension) : Pyramid_Player(symbol)
{

    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void Pyramid_RandomPlayer::get_move(int &x, int &y)
{
    x = (int)(rand() / (RAND_MAX + 1.0) * dimension); // x can be 0, 1, or 2
    int max_y;
    if (x == 0)
    {
        y = 2; // top row has 1 position
    }
    else if (x == 1)
    {
        y = rand() % 3 + 1; // middle row has 3 positions
    }
    else
    {
        y = rand() % 5; // bottom row has 5 positions
    }
}