//
// Created by J on 25/04/2021.
//

#include "library.h"
#include <stdio.h>

/* This function returns the amount of moves available for a player */
int movesAvailable(enum piece player)
{
    char position[3];           //string variable to hold current position
    int validMoves = 0;

    //loop through each of the 64 squares
    for (int i = 1; i < 9; i++) {                  //rows
        for (int j = 1; j < 9; j++) {              //columns

            //only call check function on the empty squares
            if (board[i][j].square == EMPTY) {
                position[0] = 'a'+i-1;              //column of move (a-h)
                position[1] = '0'+j;                //row of move (1-8)
                validMoves += findValidMoves(position,player,1);    //check if position is a valid move
                printf("Valid moves for (%d %d) = %d\n",i,j,validMoves);
            }
            else {
                printf("%d %d Not available\n",i,j);
            }
        }
    }
    return validMoves;
}