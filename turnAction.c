//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include "library.h"

void turnAction()
{
    static enum piece currPlayer = BLACK;
    char choice[2];
    int check;

    switch (currPlayer) {
        case WHITE:
            puts("Current player is White");
            break;
        case BLACK:
            puts("Current player is Black");
            break;
        default:
            break;
    }

    do {
        printf("%s","Enter the position you would like to take:\n");
        scanf("%3s",choice);
        check = findValidMoves(choice, currPlayer);
        if (check == 0) {
            puts("Not a valid move");
        }
    } while (check == 0);

    printBoard();

    //swap player turn
    switch (currPlayer) {
        case WHITE:
            currPlayer = BLACK;
            break;
        case BLACK:
            currPlayer = WHITE;
            break;
        default:
            break;
    }

}