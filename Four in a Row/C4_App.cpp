#include <bits/stdc++.h>
#include "C4_Classes.hpp"
#include "C4_RandomPlayer.cpp"
#include "C4_Player.cpp"
#include "C4_GameManager.cpp"
#include "C4_Board.cpp"
#include "C4_AI.cpp"

void C4_APP();

int main() {
    cout << "Welcome to AmrMsCLL's C4 Game. :)\n";
    C4_APP();
}

void C4_APP() {
    C4_Board* tmp = new C4_Board(); 
    C4_Player* players[2];
    players[0] = new C4_Player(1, 'x');
        
    int choice; cout << "Press 1 if you want to play with RandomPlayer(not smart only random moves), 2 if you don't: "; cin >> choice;
    
    if (choice != 1)
        players[1] = new C4_Player(2, 'o');
    else
        players[1] = new C4_RandomPlayer ('o');
        // players[1] = new C4_AI (AI, 'O'); // for smart ai player

    C4_GameManager C4_Game(tmp, players);
        C4_Game.run();
    int try_again; cout << "Enter 1 to play Connect four again 2 to leave the program : "; cin >> try_again;
        if(try_again == 1)
            C4_APP();
        else
            system ("pause");   
}
