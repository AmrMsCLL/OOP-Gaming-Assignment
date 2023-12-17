#include <bits/stdc++.h>
#include "Classes_Header.h"
using namespace std;

XO5_Player::XO5_Player(char symbol) {
    this->symbol = symbol;
}

XO5_Player::XO5_Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void XO5_Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) separated by spaces : ";
    cin >> x >> y;
}

string XO5_Player::to_string(){
    return "Player: " + name ;
}

char XO5_Player::get_symbol() {
    return symbol;
}