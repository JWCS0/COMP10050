//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include "library.h"

void turnAction()
{
    char choice[2];
    int check;
    extern int gameFinish;
    extern enum piece currPlayer;

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

    //No moves possible
    if (black.score + white.score == 64 || (movesAvailable(BLACK) == 0 && movesAvailable(WHITE) == 0)) {
        gameFinish = 1;
    }
    //Current player has no valid moves
    else if (movesAvailable(currPlayer) == 0) {
        puts("No valid moves");
        do {
            printf("%s","Enter the position you would like to take:\n");
            scanf("%2s",choice);
        } while (choice[0] != 'p');
    }
    else {
        do {
            printf("%s","Enter the position you would like to take:\n");
            scanf("%3s",choice);
            check = findValidMoves(choice, currPlayer,0);
            if (check == 0) {
                puts("Not a valid move");
            }
        } while (check == 0);
    }

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