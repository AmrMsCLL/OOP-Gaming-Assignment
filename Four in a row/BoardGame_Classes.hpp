#include <bits/stdc++.h>
#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
using namespace std;

class Board {
protected:
    int n_rows, n_cols;
    char** board;
    int  n_moves = 0;
public:
    virtual bool update_board (int x, int y, char symbol) = 0;
    virtual bool is_winner() = 0;
    virtual bool is_draw() = 0;
    virtual void display_board() = 0;
    virtual bool game_is_over() = 0;
};

class X_O_Board:public Board {
public:
   X_O_Board ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_winner();
   bool is_draw();
   bool game_is_over();
};

class C4_Board:public Board {
private:
    int next_empty[7] = {5,5,5,5,5,5,5};
public:
   C4_Board ();
   bool update_board (int x, int y, char mark);
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
    Player(char symbol); // Needed for computer players
    Player(int order, char symbol);
    
    virtual void get_move(int& x, int& y);
    // virtual void C4_get_move(int &y);
    string to_string();
    char get_symbol();
};

class C4_Player:public Player {
    void get_move(int& x , int& y);
};

class RandomPlayer: public Player {
    protected:
        int dimension;
    public:
        RandomPlayer (char symbol, int dimension);
        void get_move(int& x, int& y);
};

class C4_RandomPlayer: public Player {
    void get_move(int&x, int&y);
};

class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(){}
    GameManager(Board*, Player* playerPtr[2]);
    virtual void run();
};

#endif