//
// Created by ahmad on 12/14/2023.
//

#include "new_random.h"

new_random::new_random(char symbol, int dimension) : new_player(symbol)
{

    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void new_random::get_move(int &x, int &y)
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