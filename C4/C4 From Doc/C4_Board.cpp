#include <bits/stdc++.h>
#include "C4_HDeclarations.h"

using namespace std;

// done
C4_Board::C4_Board () {
   n_rows = 6;
   n_cols = 7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = 0;
   }
}
// done
void C4_Board::display_board() {
   cout << "\n---------------------------------------------------------";
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n| ";
      for (int j: {0,1,2,3,4,5,6}) {
         cout << "(" << i << "," << j << ")";
         cout << setw(2) << board [i][j] << "| ";
      }
      cout << "\n---------------------------------------------------------";
   }
   cout << endl;
}

bool C4_Board::update_board (int x, int y, char mark){
   if (!(x < 0 || x > 5 || y < 0 || y > 6) && (board[x][y] == 0)) {
      board[x][y] = toupper(mark);
      n_moves++;
      return true;
   }
   else if (1 == 2) {
      cout << "INVALID MOVE!!. Try Again";
      // bluh
   }
   else
      cout << "INVALID MOVE!!. Try Again";
      return false;
}

// Method to check for a win
bool C4_Board::is_winner() {
}

bool C4_Board::is_draw() {
   for (int col = 0; col < 6; ++col) {
        if (board[0][col] == 0) {
            return false;
        }
    }
   return true;
   // return (n_moves == 42 && !is_winner());
}

bool C4_Board::game_is_over () {
   // return isWin(token) || isDraw();
    return n_moves >= 9;
}
