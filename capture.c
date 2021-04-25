//
// Created by J on 23/04/2021.
//
#include "library.h"

int capture(int row, int column, int direction, enum piece type)
{
    int captured = 0;

    while (board[row][column].square != type) {
        board[row][column].square = type;
        row += ordDirections[direction].xMod;
        column += ordDirections[direction].yMod;
        captured++;
    }

    return captured;
}
