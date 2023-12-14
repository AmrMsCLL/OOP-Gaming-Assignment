cmake_minimum_required(VERSION 3.26)
project(5x5_tic_tac_toe)

set(CMAKE_CXX_STANDARD 23)

add_executable(5x5_tic_tac_toe
        GameManager.cpp
        Player.cpp
        GameManager.cpp
        BoardGame_Classes.hpp
        BoardGame_Classes.hpp
        X_O_App.cpp
        X_O_Board.cpp
        RandomPlayer.cpp)
