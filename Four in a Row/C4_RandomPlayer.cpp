#include <bits/stdc++.h>
#include "C4_Classes.hpp"
using namespace std;


C4_RandomPlayer::C4_RandomPlayer (char symbol):C4_Player(symbol)
{
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

void C4_RandomPlayer::get_move (int& x, int& y) {
    srand(time(0));
    y = rand() % 7 + 1;
}
