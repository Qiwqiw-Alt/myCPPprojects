cmake_minimum_required(VERSION 4.1)
project(hangmanGame)

set(CMAKE_CXX_STANDARD 14)

add_executable(hangmanGame
        main.cpp
        RandomWords.cpp
        RandomWords.h
        GuessingProgress.cpp
        GuessingProgress.h
        HangmanFigure.cpp
        HangmanFigure.h)
