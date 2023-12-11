#include <bits/stdc++.h>
#ifndef _C4_H
#define _C4_H

using namespace std;

const int ROWS = 6;
const int COLUMNS = 7;
const char EMPTY = '.';
const char PLAYER_ONE = 'X';
const char PLAYER_TWO = 'O';

class C4Board{
protected:
    vector<vector<char>> board;
public:
    C4Board();
    void displayBoard();
    bool playerMove(int column, char token);
    bool isWin(char token);   
    bool isDraw();
    bool isGameOver(char token);
};

class GameManager{
private:
    C4Board board;
    char currentPlayer;
public:
    GameManager();
    void switchPlayer();
    void playGame();
};

#endif
