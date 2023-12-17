#include <bits/stdc++.h>
#include "Classes_Header.h"

#include "Pyramid_Board.cpp"
#include "Pyramid_GameManager.cpp"
#include "Pyramid_Player.cpp"
#include "Pyramid_RandomPlayer.cpp"

#include "C4_Board.cpp"
#include "C4_GameManager.cpp"
#include "C4_Player.cpp"
#include "C4_RandomPlayer.cpp"

#include "XO5_Board.cpp"
#include "XO5_GameManager.cpp"
#include "XO5_Player.cpp"
#include "XO5_RandomPlayer.cpp"

void PYRAMID_APP(); 
void C4_APP();
void XO5_APP();

int main() {
    cout << "Welcome to integrated BoardGames Made By Amr, Ahmed, Medhat. :)\n"; 
    int game = 3; cout << "Please Choose a Game. \n1-for Pyramid XO.\n2-for Four in a Row. \n3-for 5x5 XO.\n0-To Exit.  \nYour Choice: "; cin >> game;
    
    if (game == 1){
        cout << "Welcome to Ahmed Saber's Pyramid XO Game. :)\n";
        PYRAMID_APP();
    }
    else if (game == 2) {
        cout << "Welcome to AmrMsCLL's C4 Game. :)\n";
        C4_APP();
    }
    else if (game == 3) {
        cout << "Welcome to Medhat Ahmed's 5x5 XO Game. :)\n";
        XO5_APP();
    }
    else if (game == 0) {
        exit(0);
    }
    else {
        cout << "INVALID OPTION!!, Try Again\n";
        main();
    }
}

void PYRAMID_APP() {
    Pyramid_Board* tmp = new Pyramid_Board(); 
    Pyramid_Player *players[2];
    players[0] = new Pyramid_Player(1, 'x');
    
    int choice; cout << "Press 1 if you want to play with RandomPlayer(not smart only random moves), 2 if you don't: "; cin >> choice;
    
    if (choice != 1)
        players[1] = new Pyramid_Player(2, 'o');
    else
        players[1] = new Pyramid_RandomPlayer('o', 3);
        // players[1] = new Pyramid_AI(AI, 'o) // for smart ai player

    Pyramid_GameManager Pyramid_Game(tmp, players);
    Pyramid_Game.run();
    int try_again; cout << "Enter 1 to play pyramid XO again or 2 to Play another game or 3 to leave the program : "; cin >> try_again;
        if (try_again == 1)
            PYRAMID_APP();
        else if (try_again = 2)
            main();
        else
            system ("pause");
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
    int try_again; cout << "Enter 1 to play Connect four again or 2 to choose another game or 3 to leave the program : "; cin >> try_again;
        if(try_again == 1)
            C4_APP();
        else if (try_again = 2)
            main();
        else
            system ("pause");   
}
void XO5_APP() {
    XO5_Board* tmp = new XO5_Board();     
    XO5_Player* players[2];
    players[0] = new XO5_Player(1, 'x');

    int choice; cout << "Press 1 if you want to play with RandomPlayer(not smart only random moves), 2 if you don't: "; cin >> choice;
    
    if (choice != 1)
        players[1] = new XO5_Player(2, 'o');
    else
        players[1] = new XO5_RandomPlayer('o', 5);
        // players[1] = new C4_AI (AI, 'O'); // for smart ai player

    XO5_GameManager XO5_Game(tmp, players);
        XO5_Game.run();
    int try_again; cout << "Enter 1 to play 5x5 XO again or 2 to choose another game or 3 to leave the program : "; cin >> try_again;
        if (try_again == 1)
            XO5_APP();
        else if (try_again = 2)
            main();
        else
            system("pause");
}
