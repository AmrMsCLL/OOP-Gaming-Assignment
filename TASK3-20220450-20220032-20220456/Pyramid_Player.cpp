#include <bits/stdc++.h>
#include "Classes_Header.h"
using namespace std;

Pyramid_Player::Pyramid_Player(char symbol)
{
    this->symbol = symbol;
}

Pyramid_Player::Pyramid_Player(int order, char symbol)
{
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Pyramid_Player::get_move(int &x, int &y)
{
    x = 0, y = 0;
    cout << "\nPlease enter your move x (0 to 2), y (0 to 4) separated by spaces: ";
    cin >> x >> y;
        while((x == 0 && (y == 0 || y == 1|| y == 3|| y == 4)) || (x == 1 && (y == 0 || y == 4))) {
            cout << "INVALID MOVE!!. Try Again!\n";
            cin >> x >> y;
        }
}

string Pyramid_Player::to_string()
{
    return "Player: " + name;
}

char Pyramid_Player::get_symbol()
{
    return symbol;
}