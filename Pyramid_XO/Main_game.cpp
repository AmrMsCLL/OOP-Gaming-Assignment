#include <iostream>
#include "Pyramid_Board.h"
#include "Pyramid_Board.cpp"
#include "new_Game.h"
#include "new_Game.cpp"
#include "new_random.h"
#include "new_random.cpp"
#include "new_player.h"
#include "new_player.cpp"

using namespace std;

int main()
{
    int choice;
    new_player *players[2];
    players[0] = new new_player(1, 'x');

    cout << "Welcome to FCAI X-O Pyramid Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new new_player(2, 'o');
    else
        players[1] = new new_random('o', 3);

    new_Game b(new Pyramid_Board(), players);
    b.run();
    system("pause");
}