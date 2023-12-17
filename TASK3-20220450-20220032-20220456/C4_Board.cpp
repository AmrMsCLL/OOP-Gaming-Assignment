#include <bits/stdc++.h>
#include"Classes_Header.h"
using namespace std;

C4_Board::C4_Board () {
   n_rows = 6;
   n_cols = 7;
   board = new char*[n_rows];
   for (int i = 0; i < n_rows; i++) {
      board [i] = new char[n_cols];
      for (int j = 0; j < n_cols; j++)
         board[i][j] = ' ';
   }
}

bool C4_Board::update_board (int x, int y, char mark){
   if (y < 1 || y > 7) {
        cout << "INVALID MOVE!! Column number must be between 1 and 7. Try Again!\n";
        return false;
   }
   if (next_empty[y - 1] == -1){
      cout << "INVALID MOVE!!. Try Again!\n";
      return false;
   }
   else {
      board[next_empty[y - 1]][y - 1] = toupper(mark);
      next_empty[y - 1] -= 1;
      n_moves++;
      return true;
   }
}

void C4_Board::display_board() {
   cout << "\n-----------------------------\n";
   cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |";
   cout << "\n-----------------------------";
   for (int i: {0,1,2,3,4,5}) {
      cout << "\n|";
      for (int j: {0,1,2,3,4,5,6}) {
         cout << setw(2) << board [i][j] << " |";
      }
   cout << "\n-----------------------------";
   }
   cout << endl;
}

bool C4_Board::is_winner() {
    // Check horizontal lines
    for (int row = 0; row < n_rows; row++)
        for (int col = 0; col < n_cols - 3; col++)
            if (board[row][col] != ' ' && board[row][col] == board[row][col + 1] && board[row][col] == board[row][col + 2] && board[row][col] == board[row][col + 3])
                return true;

    // Check vertical lines
    for (int col = 0; col < n_cols; col++)
        for (int row = 0; row < n_rows - 3; row++)
            if (board[row][col] != ' ' && board[row][col] == board[row + 1][col] && board[row][col] == board[row + 2][col] && board[row][col] == board[row + 3][col])
                return true;

    // Check for ascending diagonal lines
    for (int row = 3; row < n_rows; row++)
        for (int col = 0; col < n_cols - 3; col++)
            if (board[row][col] != ' ' && board[row][col] == board[row - 1][col + 1] && board[row][col] == board[row - 2][col + 2] && board[row][col] == board[row - 3][col + 3])
                return true;

    // Check for descending diagonal lines
    for (int row = 0; row < n_rows - 3; row++)
        for (int col = 0; col < n_cols - 3; col++)
            if (board[row][col] != ' ' && board[row][col] == board[row + 1][col + 1] && board[row][col] == board[row + 2][col + 2] && board[row][col] == board[row + 3][col + 3])
                return true;

    return false;
}

bool C4_Board::is_draw() {
   if (n_moves == 42 && !is_winner())  
      return true;
   else 
      return false;
}

bool C4_Board::game_is_over () {
   if (n_moves >= 42 || is_winner() == true || is_draw() == true)
      return true;
   else 
      return false;
}