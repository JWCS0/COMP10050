cmake_minimum_required(VERSION 3.17)
project(Assignment_2 C)

set(CMAKE_C_STANDARD 99)

add_executable(Assignment_2 main.c printBoard.c initializeGame.c library.h findValidMoves.c turnAction.c capture.c movesAvailable.c printWinner.c)