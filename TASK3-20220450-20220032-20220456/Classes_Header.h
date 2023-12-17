#ifndef _BoardGame_CLASSES_H
#define _BoardGame_CLASSES_H
#include <bits/stdc++.h>
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
class Player {
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
class RandomPlayer:public Player {
protected:
    int dimension;
public:
    RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);
};
class GameManager {
private:
    Board* boardPtr;
    Player* players[2];
public:
    GameManager(Board*, Player* playerPtr[2]);
    void run();
};

// Pyramid XO Classes
class Pyramid_Board:public Board {
public:
    Pyramid_Board ();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};
class Pyramid_Player {
protected:
    string name;
    char symbol;
public:
    Pyramid_Player (char symbol);
    Pyramid_Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};
class Pyramid_RandomPlayer:public Pyramid_Player{
protected:
        int dimension;
public: 
    Pyramid_RandomPlayer (char symbol, int dimension);
    void get_move(int& x, int& y);   
};
class Pyramid_GameManager {
private:
    Pyramid_Board* boardPtr;
    Pyramid_Player* players[2];
public:
    Pyramid_GameManager(Pyramid_Board*bPtr, Pyramid_Player* playerPtr[2]);
    void run();
};

// Four in a row Classes
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
class C4_Player {
protected:        
    string name;
    char symbol;
public:
    C4_Player(char symbol);
    C4_Player(int order, char symbol);
    
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};
class C4_RandomPlayer:public C4_Player {
public:
    C4_RandomPlayer(char symbol);
    void get_move(int&x, int&y);
};
class C4_GameManager { 
private:
    Board* boardPtr;
    C4_Player* players[2];
public:
    C4_GameManager(Board*, C4_Player* playerPtr[2]);
    void run();
};

// 5x5 X O Classes
class XO5_Board:public Board {
protected:
    int counter = 0;
    int count1 = 0;
    int count2 = 0;
    int count = 0;
public:
   XO5_Board ();
   bool update_board (int x, int y, char mark);
   void display_board();
   bool is_draw();
   bool is_winner();
   bool game_is_over();
};
class XO5_Player {
protected:
    string name;
    char symbol;
public:
    XO5_Player (char symbol);
    XO5_Player (int order, char symbol);
    virtual void get_move(int& x, int& y);
    string to_string();
    char get_symbol();
};
class XO5_RandomPlayer:public XO5_Player {
protected:
    int dimension;
public:
    XO5_RandomPlayer (char symbol, int dimension);
    void get_move (int& x, int& y);    
};
class XO5_GameManager {
private:
    Board* boardPtr;
    XO5_Player* players[2];
public: 
    XO5_GameManager(Board*, XO5_Player* playerPtr[2]);
    void run();    
};

#endif