#include "Pyramid_Board.h"
#include <iostream>
using namespace std;
Pyramid_Board ::Pyramid_Board()
{
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = ' ';
    }
    board[0][0] = board[0][1] = board[0][3] = board[0][4] = board[1][0] = board[1][4] =  'A';

}
bool Pyramid_Board::update_board(int x, int y, char mark)
{

    if (!(x < 0 || x > 2 || y < 0 || y > 4) && (board[x][y] == ' '))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Pyramid_Board::display_board()
{
    cout << "                        |" << '(' << 0 << ',' << 2 << ')' << "   " << board[0][2] << "  |\n\n";
    cout << "            |";
    for (int j : {1, 2, 3})
        cout << '(' << 1 << ',' << j << ')' << "   " << board[1][j] << "  |";
    cout << "\n\n|";
    for (int j : {0, 1, 2, 3, 4})
        cout << '(' << 2 << ',' << j << ')' << "   " << board[2][j] << "  |";
    cout << "\n\n";
}

bool Pyramid_Board::is_winner()
{
    if ((board[0][2] == board[1][1] && board[2][0] == board[1][1]) && (board[0][2] == 'X' || board[0][2] == 'O'))
    {
        return true;
    }
    else if ((board[0][2] == board[1][3] && board[2][4] == board[1][3]) && (board[0][2] == 'X' || board[0][2] == 'O'))
    {
        return true;
    }
    else if ((board[1][1] == board[1][2] && board[1][2] == board[1][3]) && (board[1][1] == 'X' || board[1][1] == 'O'))
    {
        return true;
    }
    else if((board[0][2] == board[1][2] && board[1][2] == board[2][2]) && (board[0][2] == 'X' || board[0][2] == 'O'))
    {
        return true;
    }
    else if((board[2][0] == board[2][1] && board[2][1] == board[2][2]) && (board[2][0] == 'X' || board[2][0] == 'O') ||
            (board[2][1] == board[2][2] && board[2][2] == board[2][3]) && (board[2][1] == 'X' || board[2][1] == 'O')||
            (board[2][2] == board[2][3] && board[2][3] == board[2][4]) && (board[2][2] == 'X' || board[2][2] == 'O'))
        return true;
    else
        return false;
}

bool Pyramid_Board::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool Pyramid_Board::game_is_over()
{
    return n_moves >= 9;
}
