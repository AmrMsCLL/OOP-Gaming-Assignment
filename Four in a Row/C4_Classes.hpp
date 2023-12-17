#include <bits/stdc++.h>
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board {
protected:
public:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
    virtual bool update_board (int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};

class C4_Board:public Board {
private:
    int next_empty[7] = {5,5,5,5,5,5,5};
public:
    C4_Board ();
    bool update_board (int x, int y, char mark);
    void undo_move(int col);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Player{
protected:        
    string name;
    char symbol;
public:
    Player(){}
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    
    virtual void get_move(int& x, int& y);
    // virtual void C4_get_move(int &y);
    string to_string();
    char get_symbol();
};

class C4_Player {
    protected:        
    string name;
    char symbol;
public:
    C4_Player(char symbol); // Needed for computer players
    C4_Player(int order, char symbol);
    
    virtual void get_move(int& x, int& y);
    // virtual void C4_get_move(int &y);
    string to_string();
    char get_symbol();
};

class C4_AI:public C4_Player{
protected:
    C4_Board* board;
public:
    C4_AI(C4_Board* bo, char s);
    void get_move(int& x, int& y);
    int findLowestEmptyRow(int col);
    int minimax(int d, bool isMaximizing, int alpha, int beta);
    int evaluateBoard();
    int evaluatePosition(int row, int col, int deltaRow, int deltaCol);
    int scoreForAdjacentPieces(int row, int col);
    int centerColumnScore();
    int blockingScore();
    int winningScore();
};

class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

class C4_RandomPlayer: public C4_Player {
public:
    C4_RandomPlayer(char symbol);
    void get_move(int&x, int&y);
};

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
};

class C4_GameManager{ 
private:
    Board* boardPtr;
    C4_Player* players[2];
public:
    C4_GameManager(Board*, C4_Player* playerPtr[2]);
    void run();
};

#endif