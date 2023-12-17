#include <bits/stdc++.h>
#include "Classes_Header.h"

using namespace std;

XO5_Board::XO5_Board () {
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

bool XO5_Board::update_board (int x, int y, char mark){
   if (((x >= 0 && x <= 4) || (y>=0 && y <=4)) && (board[x+2][y+2] == ' ')) {
      board[x+2][y+2] = toupper(mark);
      n_moves++;
      return true;
   }
   else
       cout<<"INVALID MOVE!!. Try Again.\n";
      return false;
}

void XO5_Board::display_board() {
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

bool XO5_Board::is_winner() {
XO5_Board b;

    for (int i = 2; i <=6 ; ++i)
        for (int j = 2; j <=6 ; ++j) {
            if (board[i][j] == 'x' || board[i][j] == 'X') {
                if ((board[i][j+1] == 'x' || board[i][j+1] == 'X')&&(board[i][j+2] == 'x' || board[i][j+2] == 'X'))
                    count1++;
                
                if((board[i][j-1] == 'x' || board[i][j-1] == 'X')&&(board[i][j-2] == 'x' || board[i][j-2] == 'X'))
                    count1++;
                
                if ((board[i+1][j] == 'x' || board[i+1][j] == 'X')&&(board[i+2][j] == 'x' || board[i+2][j] == 'X'))
                    count1++;
                
                if((board[i-1][j] == 'x' || board[i-1][j] == 'X')&&(board[i-2][j] == 'x' || board[i-2][j] == 'X'))
                    count1++;
                
                if((board[i+1][j+1] == 'x' || board[i+1][j+1] == 'X')&& (board[i+2][j+2] == 'x' || board[i+2][j+2] == 'X'))
                    count1++;
            
                if((board[i-1][j-1] == 'x' || board[i-1][j-1] == 'X')&&(board[i-2][j-2] == 'x' ||board[i-2][j-2] == 'X'))
                    count1++;
                
                if((board[i+1][j-1]=='x'||board[i+1][j-1]=='X')&&(board[i+2][j-2]=='x'||board[i+2][j-2]=='X'))
                        count1++;
                
                if((board[i-1][j+1]=='x'||board[i-1][j+1]=='X')&&(board[i-2][j+2]=='x'||board[i-2][j+2]=='X'))
                    count1++;
                
            }
            else if(board[i][j] == 'o' || board[i][j] == 'O'){
                if ((board[i][j+1] == 'o' || board[i][j+1] == 'O')&&(board[i][j+2] == 'o' || board[i][j+2] == 'O'))
                    count2++;
                
                if((board[i][j-1] == 'o' || board[i][j-1] == 'O')&&(board[i][j-2] == 'o' || board[i][j-2] == 'O'))
                    count2++;
                
                if ((board[i+1][j] == 'o' || board[i+1][j] == 'O')&&(board[i+2][j] == 'o' || board[i+2][j] == 'O'))
                    count2++;
                
                if((board[i-1][j] == 'o' || board[i-1][j] == 'O')&&(board[i-2][j] == 'o' || board[i-2][j] == 'O'))
                    count2++;
                
                if((board[i+1][j+1] == 'o' || board[i+1][j+1] == 'O')&& (board[i+2][j+2] == 'o' || board[i+2][j+2] == 'O'))
                    count2++;
                
                if((board[i-1][j-1] == 'o' || board[i-1][j-1] == 'O')&&(board[i-2][j-2] == 'o' ||board[i-2][j-2] == 'O'))
                    count2++;
                
                if((board[i+1][j-1]=='o'||board[i+1][j-1]=='O')&&(board[i+2][j-2]=='o'||board[i+2][j-2]=='O'))
                    count2++;
                
                if((board[i-1][j+1]=='o'||board[i-1][j+1]=='O')&&(board[i-2][j+2]=='o'||board[i-2][j+2]=='O'))
                    count2++;

            }

        }

    if(count1>count2) 
        return true;

    else if(count1<count2)
        return false;
    
    else
        return true;

}

bool XO5_Board::is_draw() {
    return (count1==count2);
}

bool XO5_Board::game_is_over () {
    return n_moves >= 24 ;
}