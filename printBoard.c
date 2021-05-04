//
// Created by J on 09/04/2021.
//

#include <stdio.h>
#include "library.h"

/* This function prints out the current state of the board */
void printBoard()
{
    printf("%s","   a  b  c  d  e  f  g  h\n");         //horizontal indexing
    for (size_t i = 1; i <= 8; i++) {                   //go through each of the 8 rows
        printf("%d  ",i);                               //current row
        for (size_t j = 1; j <= 8; j++) {               //go through each of the 8 columns

            //print whether the square is black, white or empty
            switch (board[i][j].square) {
                case EMPTY:
                    printf("%c  ", '-');
                    break;
                case BLACK:
                    printf("%c  ",'B');
                    break;
                case WHITE:
                    printf("%c  ",'W');
                    break;
                case EOB:
                    continue;
            }
        }
        printf("%d",i);
        puts("");
    }
    printf("%s","   a  b  c  d  e  f  g  h\n");

    printf("%s %s %d - %d %s %s\n\n","Score: (Black)",black.name,black.score,white.score,white.name,"(White)");
}