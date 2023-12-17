#include <iostream>
#include "Classes_header.h"
using namespace std;

XO5_GameManager::XO5_GameManager(Board* bPtr, XO5_Player* playerPtr[2] ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void XO5_GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            cout  << "it's " << players[i]->to_string() << "'s Turn : ";
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
        }

        }
    if(boardPtr->is_winner()) { ;
        if (boardPtr->is_draw()) {
            cout << "It's a Draw!\n";
            return;
        } else if (boardPtr->is_winner()) {
            cout << players[0]->to_string() << " Is The Winner\n";
            return;
        }
    }
        else if (!boardPtr->is_winner()) {
            cout << players[1]->to_string() << " Is The Winner\n";
            return;
        }
    }


