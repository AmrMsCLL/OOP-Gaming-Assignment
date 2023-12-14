#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
#include "RandomPlayer.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "C4_Board.cpp"

int main() {
    cout << "Welcome to AmrMsCLL C4 Game. :)\n";
    
    // int game_choice; cout << "Enter 1 For C4 : ";

    Player* players[2];
    players[0] = new Player (1, 'x');

    int choice;
    cout << "Press 1 if you want to play with computer, 2 if you don't: ";
    cin >> choice;
    
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 3);

    GameManager C4_game (new C4_Board(), players);
        C4_game.run();
        system ("pause");
}