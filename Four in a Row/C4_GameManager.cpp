#include <bits/stdc++.h>
#include "C4_Classes.hpp"
using namespace std;

C4_GameManager::C4_GameManager(Board* bPtr, C4_Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void C4_GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            cout  << "it's " << players[i]->to_string() << "'s Turn\n";
            players[i]->get_move(x, y);
            while (!boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " Is The Winner\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "It's a Draw!\n";
                return;
            }
        }
    }
}
