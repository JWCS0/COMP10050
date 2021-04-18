//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include "library.h"

void initializeBoard()
{
    board[3][3].square = WHITE;
    board[3][4].square = BLACK;
    board[4][3].square = BLACK;
    board[4][4].square = WHITE;

    black.score = 2;
    black.piece = BLACK;
    white.score = 2;
    white.piece = WHITE;
}