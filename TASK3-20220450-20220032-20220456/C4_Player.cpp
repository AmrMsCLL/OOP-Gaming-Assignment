#include <bits/stdc++.h>
#include "Classes_Header.h"
using namespace std;


C4_Player::C4_Player(char symbol) {
    this->symbol = symbol;
}

C4_Player::C4_Player(int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}

void C4_Player::get_move (int& x, int& y) {
        cout << "\nPlease enter your move (1 to 7) : ";
        cin >> y;
        return;
}

string C4_Player::to_string(){
    return "Player: " + name ;
}

char C4_Player::get_symbol() {
    return symbol;
}