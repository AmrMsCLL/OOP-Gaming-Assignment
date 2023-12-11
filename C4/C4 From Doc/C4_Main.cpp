#include <bits/stdc++.h>
#include "C4_HDeclarations.h"
#include "C4_Player.cpp"
#include "C4_GameManager.cpp"
#include "C4_Board.cpp"

using namespace std;

int main() {
    cout << "Welcome to AmrCLL C4 Game. :)\n";

    // int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    // cout << "Press 1 if you want to play with a Computer: ";
    // cin >> choice;
    // if (choice != 1)
        players[1] = new Player (2, 'o');
    // else
        // // Player pointer points to child
        // players[1] = new RandomPlayer ('o', 3);

    GameManager C4_game (new C4_Board(), players);
    C4_game.run();
    system ("pause");
return 0;
}