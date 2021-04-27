//
// Created by J on 09/04/2021.
//

#include <stdio.h>
#include "library.h"

void printBoard()
{
    for (size_t i = 1; i <= 8; i++) {
        printf("%d  ",i);
        for (size_t j = 1; j <= 8; j++) {
            switch (board[i][j].square) {
                case EMPTY:
                    printf("%c  ", ' ');
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
        puts("");
    }
    printf("%s","   a  b  c  d  e  f  g  h\n");

    printf("%s %d - %d %s\n","Current Score: Black",black.score,white.score,"White");
}