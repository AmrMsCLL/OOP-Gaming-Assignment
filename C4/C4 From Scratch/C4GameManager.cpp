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
            std::cout << "Player " << currentPlayer << ", enter a column number to place your token: ";
            std::cin >> column;

            if (!board.playerMove(column - 1, currentPlayer)) {
                std::cout << "Invalid move. Try again." << std::endl;
                continue;
            }

            if (board.isWin(currentPlayer)) {
                board.displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                isRunning = false;
            } else if (board.isDraw()) {
                board.displayBoard();
                std::cout << "It's a draw!" << std::endl;
                isRunning = false;
            }

            switchPlayer();
        }
    }