//
// Created by J on 23/04/2021.
//
#include "library.h"
#include <stdio.h>

int capture(int row, int column, int direction, enum piece type)
{
    int captured = 0;

    printf("%d %d\n", row, column);

    puts("DEBUG START");
    printf("%d vs %d\n",board[row][column].square,type);
    while (board[row][column].square != type) {
        board[row][column].square = type;
        row += ordDirections[direction].xMod*-1;
        column += ordDirections[direction].yMod*-1;
        captured++;
        printf("Row col %d %d\n", row, column);
        printf("%d vs %d\n",board[row][column].square,type);
    }

    printf("%d",captured);

    return captured;
}