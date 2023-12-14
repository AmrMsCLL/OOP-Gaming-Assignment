cmake_minimum_required(VERSION 3.27)
project(board)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(board
        BoardGame_Classes.hpp
        Main_game.cpp
        new_Game.cpp
        new_Game.h
        new_player.cpp
        new_player.h
        Player.cpp
        Pyramid_Board.cpp
        Pyramid_Board.h
        RandomPlayer.cpp
        new_random.h
        new_random.cpp)
