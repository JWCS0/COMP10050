//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include "library.h"

void turnAction()
{
    static enum piece currPlayer = BLACK;
    char choice[2];

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

    printf("%s","Enter the position you would like to take:\n");
    scanf("%3s",choice);

    if (isValidMove(choice,currPlayer)) {
        puts("That is a valid move");
    }

    else {
        puts("Not a valid move");
    }


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