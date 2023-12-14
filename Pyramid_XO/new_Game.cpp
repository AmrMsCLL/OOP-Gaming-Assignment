//
// Created by ahmad on 12/13/2023.
//

#include "new_Game.h"
#include <iostream>
new_Game::new_Game(Pyramid_Board *bPtr, new_player **playerPtr)
{
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void new_Game::run()
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over())
    {
        for (int i : {0, 1})
        {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol()))
            {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner())
            {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw())
            {
                cout << "Draw!\n";
                return;
            }
        }
    }
}