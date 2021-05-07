//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <string.h>
#include "library.h"

/* This function performs a turn in the game */
void turnAction()
{
    char choice[2];
    int check;
    extern int gameFinish;
    extern enum piece currPlayer;

    //print the current player
    switch (currPlayer) {
        case WHITE:
            printf("%s %s\n","Current player is (White)", white.name);
            break;
        case BLACK:
            printf("%s %s\n","Current player is (Black)", black.name);
            break;
        default:
            break;
    }

    //No moves possible
    if (black.score + white.score == 64) {
        puts("Board filled");
        gameFinish = 1;
    }

    else if (movesAvailable(BLACK) == 0 && movesAvailable(WHITE) == 0) {
        puts("No more moves available for either players");
        gameFinish = 1;
    }

    //Current player has no valid moves
    else if (movesAvailable(currPlayer) == 0) {
        do {
            puts("No valid moves");
            printf("%s","Enter the position you would like to take ([column][row]/p to pass):\n");
            scanf("%2s",choice);
        } while (choice[0] != 'p');
    }

    //play out a regular turn by asking for a move and executing the move if valid
    else {
        do {
            printf("%s","Enter the position you would like to take ([column][row]/p to pass):\n");
            scanf("%3s",choice);
            check = findValidMoves(choice, currPlayer,0);
            if (strcmp(choice,"p") == 0) {
                puts("Moves still possible, cannot pass");
            }
            else if (check == 0) {
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