//
// Created by J on 09/04/2021.
//

#include <stdio.h>
#include "library.h"

void printBoard()
{
    printf("%s","   a  b  c  d  e  f  g  h\n");
    for (size_t i = 0; i < 8; i++) {
        printf("%d  ",i+1);
        for (size_t j = 0; j < 8; j++) {
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
            }
        }
        puts("");
    }

    printf("%s %d - %d %s\n","Current Score: Black",black.score,white.score,"White");
}