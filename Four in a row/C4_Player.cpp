#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

Player::Player(char symbol) {
    this->symbol = symbol;
}
Player::Player (int order, char symbol) {
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

string Player::to_string(){
    return "Player: " + name ;
}

char Player::get_symbol() {
    return symbol;
}
