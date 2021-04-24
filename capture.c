//
// Created by J on 23/04/2021.
//
#include "library.h"
#include <stdio.h>

int capture(int row, int column, int direction, enum piece type)
{
    int captured = 0;


    printf("%d %d\n", row, column);

    puts("CAPTURE START");
    printf("%d vs %d\n",board[row][column].square,type);
    do {
        board[row][column].square = type;
        row += ordDirections[direction].xMod;
        column += ordDirections[direction].yMod;
        captured++;
        printf("Row col %d %d\n", row, column);
        printf("%d vs %d\n",board[row][column].square,type);
    } while (board[row][column].square != type);

    printf("Captured%d\n",captured);

    return captured;
}