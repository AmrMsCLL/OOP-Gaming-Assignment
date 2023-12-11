#include <bits/stdc++.h>
#include "C4_HDeclarations.h"

using namespace std;

// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

Player::Player (int order, char symbol) {
    cout << "Welcome Player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void Player::get_move (int& x) {
    cout << "\nPlease enter your move. Column Number 1 - 7: ";
    cin >> x >> y;
}

string Player::to_string(){
    return "Player: " + name ;
}

char Player::get_symbol() {
    return symbol;
}
