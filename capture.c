//
// Created by J on 23/04/2021.
//
#include "library.h"

/* This function captures a "line" of pieces by flipping the pieces in that direction and returns the amount captured*/
int capture(int row, int column, int direction, enum piece type)
{
    int captured = 0;

    //keep flipping the pieces until a piece of the capturer is reached
    while (board[row][column].square != type) {
        board[row][column].square = type;                   //flip the piece to capturer's color
        row += ordDirections[direction].xMod;               //increment the current position by the x offset
        column += ordDirections[direction].yMod;            //increment the current position by the y offset
        captured++;
    }

    return captured;
}
