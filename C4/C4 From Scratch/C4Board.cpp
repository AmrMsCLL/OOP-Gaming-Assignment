#include <bits/stdc++.h>
#include "C4.h"
using namespace std;

C4Board::C4Board() {
    board.resize(ROWS);
    for (auto &row : board) {
        row.resize(COLUMNS, EMPTY);
    }
}

void C4Board::displayBoard() {
    cout << "-----------------------------\n";
    cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
    cout << "-----------------------------\n";
        for (const auto &row : board) {
            cout << "| ";
            for (char cell : row) {
                cout << cell << " | ";
            }
            cout << endl;
        }
    cout << "-----------------------------\n";
    }

bool C4Board::isWin(char token) {
    // Horizontal check
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7 - 3; ++col) {
            if (board[row][col] == token && board[row][col + 1] == token &&
                board[row][col + 2] == token && board[row][col + 3] == token) {
                return true;
            }
        }
    }
    // Vertical check
    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6 - 3; ++row) {
            if (board[row][col] == token && board[row + 1][col] == token &&
                board[row + 2][col] == token && board[row + 3][col] == token) {
                return true;
            }
        }
    }
    // Diagonal (ascending) check
    for (int row = 3; row < 6; ++row) {
        for (int col = 0; col < 7 - 3; ++col) {
            if (board[row][col] == token && board[row - 1][col + 1] == token &&
                board[row - 2][col + 2] == token && board[row - 3][col + 3] == token) {
                return true;
            }
        }
    }
    // Diagonal (descending) check
    for (int row = 0; row < 6 - 3; ++row) {
        for (int col = 0; col < 7 - 3; ++col) {
            if (board[row][col] == token && board[row + 1][col + 1] == token &&
                board[row + 2][col + 2] == token && board[row + 3][col + 3] == token) {
                return true;
            }
        }
    }
    return false;
}

bool C4Board::isDraw() {
    for (int col = 0; col < 7; ++col) {
        if (board[0][col] == '.') {
            return false;
        }
    }
    return true;
}

bool C4Board::isGameOver(char token) {
    return isWin(token) || isDraw();
}

bool C4Board::playerMove(int column, char token) {
        if (column < 0 || column >= 7 || board[0][column] != '.') {
            return false;
        }
        for (int i = 6 - 1; i >= 0; --i) {
            if (board[i][column] == '.') {
                board[i][column] = token;
                return true;
            }
        }
        return false;
    }