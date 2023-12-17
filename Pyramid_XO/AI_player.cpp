#include "AI_player.h"


AI_player::AI_player(Pyramid_Board *bo, char s) : new_player(s){
    b = bo;
}

int minimax(Pyramid_Board* b, int d, bool isMaximizing){

    if(b->is_winner() && !isMaximizing) return 10;
    if(b->is_winner() && isMaximizing) return -10;
    if(d == 0 && !isMaximizing) return 10;
    if(d == 0 && isMaximizing) return -10;
    if(b->is_draw() ) return 0;


    if (isMaximizing) {
        int best = -1000;

        // Traverse all cells
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if(b->board[i][j] == ' '){
                    b->board[i][j] = 'O';
                    int score = minimax(b, d-1, false);
                    b->board[i][j] = ' ';
                    best = max(best, score);
                }
            }
        }
        return best;
    }
    else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 5; j++) {
                if (b->board[i][j] == ' ') {
                    b->board[i][j] = 'X';
                    int score = minimax(b, d - 1, true);
                    b->board[i][j] = ' ';
                    best = min(best, score);
                }
            }
        }
        return best;
    }
}



void AI_player::get_move(int &x, int &y) {
    int bestVal = -1000;
    int bestMoveX = -1;
    int bestMoveY = -1;


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {

            if (b->board[i][j] == ' ') {

                b->board[i][j] = 'O';


                int moveVal = minimax(b, 1000, false);

                b->board[i][j] = ' ';


                if (moveVal > bestVal) {
                    bestMoveX = i;
                    bestMoveY = j;
                    bestVal = moveVal;
                }
            }
        }
    }


    x = bestMoveX;
    y = bestMoveY;
}