
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

// Set the board
X_O_Board::X_O_Board () {
   n_rows = n_cols = 9;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++) {
       if(i==0||i==1||j==0||j==1||i==7||i==8||j==7||j==8){
           board[i][j]='p';
       }
       else
          board[i][j] = ' ';
      }
   }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_Board::update_board (int x, int y, char mark){
   if (((x >= 0 && x <= 4) || (y>=0 && y <=4)) && (board[x+2][y+2] == ' ')) {
      board[x+2][y+2] = toupper(mark);
      n_moves++;
      return true;
   }
   else
       cout<<"invalid \n";
      return false;
}

// Display the board and the pieces on it
void X_O_Board::display_board() {
    cout << "\n---------------------";
   for (int i: {2,3,4,5,6}) {
      cout << "\n|";
      for (int j: {2,3,4,5,6}) {
         cout << setw(2) << board [i][j] << " |";
      }
      cout << "\n---------------------";
   }
   cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool X_O_Board::is_winner() {
X_O_Board b;
    for (int i = 2; i <=6 ; ++i) {
        for (int j = 2; j <=6 ; ++j) {
            if (board[i][j] == 'x' || board[i][j] == 'X') {
                if ((board[i][j+1] == 'x' || board[i][j+1] == 'X')&&(board[i][j+2] == 'x' || board[i][j+2] == 'X')){
                    count1++;
                }
                if((board[i][j-1] == 'x' || board[i][j-1] == 'X')&&(board[i][j-2] == 'x' || board[i][j-2] == 'X')){
                    count1++;
                }
                if ((board[i+1][j] == 'x' || board[i+1][j] == 'X')&&(board[i+2][j] == 'x' || board[i+2][j] == 'X')){
                    count1++;
                }
                if((board[i-1][j] == 'x' || board[i-1][j] == 'X')&&(board[i-2][j] == 'x' || board[i-2][j] == 'X')){
                    count1++;
                }
                if((board[i+1][j+1] == 'x' || board[i+1][j+1] == 'X')&& (board[i+2][j+2] == 'x' || board[i+2][j+2] == 'X')){
                    count1++;
                }

                if((board[i-1][j-1] == 'x' || board[i-1][j-1] == 'X')&&(board[i-2][j-2] == 'x' ||board[i-2][j-2] == 'X')){
                    count1++;
                }
                if((board[i+1][j-1]=='x'||board[i+1][j-1]=='X')&&(board[i+2][j-2]=='x'||board[i+2][j-2]=='X')){
                        count1++;
                    }
                if((board[i-1][j+1]=='x'||board[i-1][j+1]=='X')&&(board[i-2][j+2]=='x'||board[i-2][j+2]=='X')){
                    count1++;
                }
            }
            else if(board[i][j] == 'o' || board[i][j] == 'O'){
                if ((board[i][j+1] == 'o' || board[i][j+1] == 'O')&&(board[i][j+2] == 'o' || board[i][j+2] == 'O')){
                    count2++;
                }
                if((board[i][j-1] == 'o' || board[i][j-1] == 'O')&&(board[i][j-2] == 'o' || board[i][j-2] == 'O')){
                    count2++;
                }
                if ((board[i+1][j] == 'o' || board[i+1][j] == 'O')&&(board[i+2][j] == 'o' || board[i+2][j] == 'O')){
                    count2++;
                }
                if((board[i-1][j] == 'o' || board[i-1][j] == 'O')&&(board[i-2][j] == 'o' || board[i-2][j] == 'O')){
                    count2++;
                }
                if((board[i+1][j+1] == 'o' || board[i+1][j+1] == 'O')&& (board[i+2][j+2] == 'o' || board[i+2][j+2] == 'O')){
                    count2++;
                }
                if((board[i-1][j-1] == 'o' || board[i-1][j-1] == 'O')&&(board[i-2][j-2] == 'o' ||board[i-2][j-2] == 'O')){
                    count2++;
                }
                if((board[i+1][j-1]=='o'||board[i+1][j-1]=='O')&&(board[i+2][j-2]=='o'||board[i+2][j-2]=='O')){
                    count2++;
                }
                if((board[i-1][j+1]=='o'||board[i-1][j+1]=='O')&&(board[i-2][j+2]=='o'||board[i-2][j+2]=='O')){
                    count2++;
                }
            }

        }

    }
    if(count1>count2) {
        return true;
    }
    else if(count1<count2) {
        return false;
    }
    else
        return true;

}

// Return true if 9 moves are done and no winner
bool X_O_Board::is_draw() {
    return (count1==count2);
}

bool X_O_Board::game_is_over () {
    return n_moves >= 24 ;
}
