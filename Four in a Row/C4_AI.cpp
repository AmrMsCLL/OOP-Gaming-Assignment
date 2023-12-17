#include <bits/stdc++.h>
#include "C4_Classes.hpp"
using namespace std;

C4_AI::C4_AI(C4_Board* bo, char s) : C4_Player(s){
    board = bo;
    this->name = "Computer AI";
    cout << "My names is " << name << endl;
}

int C4_AI::findLowestEmptyRow(int col) {
    for (int row = 5; row >= 0; row--) {
        if (board->board[row][col] == ' ') {
            return row;
        }
    }
    return -1;
}

int C4_AI::scoreForAdjacentPieces(int row, int col) {
    int score = 0;
    char AI_Piece = 'O';
    
    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (auto &dir : directions) {
        int consecutiveCount = 0;
        int dRow = dir[0], dCol = dir[1];

        for (int i = 0; i < 4; ++i) {
            int r = row + i * dRow;
            int c = col + i * dCol;

            if (r < 0 || r >= 5 || c < 0 || c >= 6) {
                break;
            }
            if (board->board[r][c] == AI_Piece) {
                consecutiveCount++;
            } 
            else 
                break;
        }
        switch (consecutiveCount) {
            case 2:
                score += 10;
                break;
            case 3:
                score += 50;
                break;
            case 4:
                score += 100;
                break;
        }
    }
    return score;
}

int C4_AI::centerColumnScore() {
    int centerScore = 0;
    int centerColumn = 7 / 2;
    char AI_Piece = 'O';
    for (int row = 0; row < 6; ++row) {
        if (board->board[row][centerColumn] == AI_Piece) {
            centerScore += 3;
        }
    }
    return centerScore;
}

int C4_AI::winningScore() {
    int winScore = 0;
    char AI_Piece = 'O';

    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            for (auto &dir : directions) {
                int myCount = 0;
                bool canWin = false;
                int dRow = dir[0], dCol = dir[1];

                for (int i = 0; i < 4; ++i) {
                    int r = row + i * dRow;
                    int c = col + i * dCol;

                    if (r < 0 || r >= 6 || c < 0 || c >= 7) {
                        break;
                    }
                    if (board->board[r][c] == AI_Piece) {
                        myCount++;
                    } else if (board->board[r][c] == ' ') {
                        if (r == 5 || board->board[r + 1][c] != ' ') {
                            canWin = true;
                        }
                        break;
                    } else {
                        break;
                    }
                }
                if (myCount == 3 && canWin) {
                    winScore += 1000;
                }
            }
        }
    }
    return winScore;
}

int C4_AI::blockingScore() {
    int blockScore = 0;
    char opponent = 'X';

    int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {-1, 1}};

    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            for (auto &dir : directions) {
                int opponentCount = 0;
                bool canBlock = false;
                int dRow = dir[0], dCol = dir[1];

                for (int i = 0; i < 4; ++i) {
                    int r = row + i * dRow;
                    int c = col + i * dCol;

                    if (r < 0 || r >= 6 || c < 0 || c >= 7) {
                        break;
                    }
                    if (board->board[r][c] == opponent) {
                        opponentCount++;
                    } else if (board->board[r][c] == ' ') {
                        if (r == 5 || board->board[r + 1][c] != ' ') {
                            canBlock = true;
                        }
                        break;
                    } else {
                        break;
                    }
                }
                if (opponentCount == 3 && canBlock) {
                    blockScore += 100;
                } else if (opponentCount == 2 && canBlock) {
                    blockScore += 10;
                }
            }
        }
    }
    return blockScore;
}

int C4_AI::evaluatePosition(int row, int col, int deltaRow, int deltaCol) {
    int myCount = 0;
    int opponentCount = 0;
    char opponentSymbol = 'X';

    for (int i = 0; i < 4; i++) {
        if (board->board[row][col] == symbol) {
            myCount++;
        } else if (board->board[row][col] == opponentSymbol) {
            opponentCount++;
        }
        row += deltaRow;
        col += deltaCol;
    }

    if (myCount == 4) {
        return 100;
    } else if (myCount == 3 && opponentCount == 0) {
        return 10;
    } else if (myCount == 2 && opponentCount == 0) {
        return 5;
    } else if (opponentCount == 3 && myCount == 0) {
        return -50;
    }
    return 0;
}

int C4_AI::evaluateBoard() {
    int score = 0;

    for (int row = 0; row < 6; row++) {
        for (int col = 0; col < 7; col++) {
            if (col <= 3) {
                score += evaluatePosition(row, col, 0, 1);
            }
            if (row <= 2) {
                score += evaluatePosition(row, col, 1, 0);
            }
            if (row <= 2 && col <= 3) {
                score += evaluatePosition(row, col, 1, 1);
            }
            if (row >= 3 && col <= 3) {
                score += evaluatePosition(row, col, -1, 1);
            }
            score += scoreForAdjacentPieces(row, col);
        }
    }
    score += centerColumnScore();
    score += blockingScore();
    score += winningScore();
    return score;
}

int C4_AI::minimax(int depth, bool isMaximizingPlayer, int alpha, int beta) {
    if (board->is_winner() && !isMaximizingPlayer) return 1000;
    if (board->is_winner() && isMaximizingPlayer) return -1000;
    if (board->is_draw()) return 0;
    if (depth == 0) return evaluateBoard();

    if (isMaximizingPlayer) {
        int bestScore = -1000;
        for (int col = 0; col < 7; col++) {
            int row = findLowestEmptyRow(col);
            if (row != -1) {
                board->board[row][col] = 'O';
                int score = minimax(depth - 1, false, alpha, beta);
                board->board[row][col] = ' ';
                bestScore = max(bestScore, score);
                alpha = max(alpha, bestScore);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return bestScore;
    } 
    else {
        int bestScore = 1000;
        for (int col = 0; col < 7; col++) {
            int row = findLowestEmptyRow(col);
            if (row != -1) {
                board->board[row][col] = 'X';
                int score = minimax(depth - 1, true, alpha, beta);
                board->board[row][col] = ' ';
                bestScore = min(bestScore, score);
                beta = min(beta, bestScore);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return bestScore;
    }
}

void C4_AI::get_move(int &x, int &y) {
    int bestScore = -1000;
    int bestMove = -1;
    int alpha = -1000;
    int beta = 1000;
    for (int col = 0; col < 7; col++) {
        int row = findLowestEmptyRow(col);
        if (row != -1) {
            board->board[row][col] = symbol;
            int score = minimax(7, false, alpha, beta);
            board->board[row][col] = ' ';
            if (score > bestScore) {
                bestScore = score;
                bestMove = col;
                if (score == 1000) break;
            }
        }
    }
    if (bestMove != -1) {
        x = findLowestEmptyRow(bestMove);
        y = bestMove + 1;
    } 
    else {
        x = -1;
        y = -1;
    }
}