#include <bits/stdc++.h>
#ifndef _C4_HDECLARATIONS_H
#define _C4_HDECLARATIONS_H

using namespace std;

class Board{
protected:
   int n_rows, n_cols;
   char** board;
   int  n_moves = 0;

public:
   // Return true  if move is valid and put it on board
   // within board boundaries in empty cell
   // Return false otherwise
   virtual bool update_board (int x, int y, char symbol) = 0;
   // Returns true if there is any winner
   // either X or O
   // Written in a complex way. DO NOT DO LIKE THIS.

   virtual bool is_winner() = 0;
   virtual bool is_draw() = 0;
   virtual void display_board() = 0;
   virtual bool game_is_over() = 0;
};

class C4_Board:public Board {
public:
    C4_Board(); // T
    bool update_board (int x, int y, char mark);
    void display_board(); // maybe done 
    bool is_winner(); // copming soon
    bool is_draw();
    bool game_is_over();
};

class Player {
protected:
    string name;
    char symbol;
public:
    Player (char symbol); // Needed for computer players
    Player (int order, char symbol);
    virtual void get_move(int& y);
    string to_string();
    char get_symbol();
};

// done fn
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
};

// coming soon need to make it stick to the lower rows before
class RandomPlayer: public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};

#endif
