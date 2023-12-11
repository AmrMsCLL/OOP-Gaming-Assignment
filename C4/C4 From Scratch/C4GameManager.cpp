#include <bits/stdc++.h>
#include "C4.h"
using namespace std;

GameManager::GameManager() {
    currentPlayer = PLAYER_ONE;
}

void GameManager::switchPlayer() {
        currentPlayer = (currentPlayer == PLAYER_ONE) ? PLAYER_TWO : PLAYER_ONE;
    }

void GameManager::playGame() {
        int column;
        bool isRunning = true;

        while (isRunning) {
            board.displayBoard();
            cout << "Player " << currentPlayer << ", enter a column number to place your token: ";
            cin >> column;

            if (!board.playerMove(column - 1, currentPlayer)) {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (board.isWin(currentPlayer)) {
                board.displayBoard();
                cout << "Player " << currentPlayer << " wins!" << endl;
                isRunning = false;
            } else if (board.isDraw()) {
                board.displayBoard();
                cout << "It's a draw!" << endl;
                isRunning = false;
            }

            switchPlayer();
        }
    }
