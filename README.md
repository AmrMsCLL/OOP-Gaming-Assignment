# Board Games

Three board games in C++, each written against one shared abstract interface, then integrated
behind a single menu. Assignment 3 for the OOP course (Dr. El-Ramly) at FCAI, Cairo University.

## The abstraction

Every game implements the same pure-virtual `Board` contract, so the game manager never knows
which game it is running:

```cpp
class Board {
public:
   virtual bool update_board(int x, int y, char mark) = 0;
   virtual bool is_winner() = 0;
   virtual bool is_draw() = 0;
   virtual void display_board() = 0;
   virtual bool game_is_over() = 0;
};
```

`Player` and `RandomPlayer` sit alongside it, so a human, a random mover or an AI are
interchangeable in the same slot.

## The games

| Game | Board | AI opponent |
| :--- | :--- | :--- |
| **Four in a Row** | 6×7, gravity-fed columns | Minimax, depth 7, alpha-beta pruned |
| **Pyramid X-O** | 3 rows of 1, 3 and 5 cells | Minimax |
| **5×5 Tic-Tac-Toe** | 5×5 play area, padded 9×9 array | Random mover |

### Four in a Row

The strongest of the three opponents. `C4_AI` searches seven plies with minimax and alpha-beta
pruning, scoring non-terminal positions by scanning every direction from each cell and weighting
runs of adjacent pieces, so it blocks threats and builds its own rather than only reacting to an
immediate win.

## Build

Each game compiles on its own, and `TASK3` builds all three behind one menu. `Main_App.cpp`
includes the other translation units directly, so compile only the app file:

```sh
g++ -std=c++17 "TASK3-20220450-20220032-20220456/Main_App.cpp" -o boardgames
./boardgames
```

Or one game on its own:

```sh
cd "Four in a Row" && g++ -std=c++17 C4_App.cpp -o c4 && ./c4
```

## Layout

```
5x5 tic tac toe/    5×5 X-O, plus the shared BoardGame_Classes.hpp
Four in a Row/      Connect Four with C4_AI (minimax + alpha-beta)
Pyramid_XO/         Pyramid X-O with AI_player
TASK3-.../          all three integrated behind one menu
```

## Credits

A three-person project. Each of us owned one game:

| Game | Author |
| :--- | :--- |
| Four in a Row | Amr Mohamed El-Sheriey — [@AmrMsCLL](https://github.com/AmrMsCLL) |
| Pyramid X-O | Ahmed Mohamed Saber |
| 5×5 Tic-Tac-Toe | Medhat Ahmed |
