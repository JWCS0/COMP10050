//
// Created by J on 27/04/2021.
//

#include "library.h"
#include <stdio.h>

void printWinner(char startTime[])
{
    int difference = black.score - white.score;

    FILE *fp;
    fp = fopen("othello_results.txt","w");

    puts("\n\n\n\nGame Completed");
    fprintf(fp,"%s %s\n","Game start time:",startTime);


    if (difference > 0) {
        printf("%s %s\n","Winner is (Black)",black.name);
        fprintf(fp,"%s %s\n","Winner is (Black)",black.name);
    }
    else if (difference < 0) {
        printf("%s %s\n","Winner is (White)", white.name);
        fprintf(fp,"%s %s\n","Winner is (White)",white.name);
    }
    else {
        printf("%s\n","Game ended in a draw");
        fprintf(fp,"%s\n","Game ended in a draw");
    }

    puts("Final Board:");
    printBoard();

    fprintf(fp,"%s\n","   a  b  c  d  e  f  g  h");
    for (size_t i = 1; i <= 8; i++) {
        fprintf(fp,"%d  ",i);
        for (size_t j = 1; j <= 8; j++) {
            switch (board[i][j].square) {
                case EMPTY:
                    fprintf(fp,"%c  ", '-');
                    break;
                case BLACK:
                    fprintf(fp,"%c  ",'B');
                    break;
                case WHITE:
                    fprintf(fp,"%c  ",'W');
                    break;
                case EOB:
                    continue;
            }
        }
        fprintf(fp,"%d",i);
        fprintf(fp,"%s","\n");
    }
    fprintf(fp,"%s\n","   a  b  c  d  e  f  g  h");

    fprintf(fp,"%s\n","Result:");
    fprintf(fp,"%s %s %d : %d %s %s","(Black)",black.name,black.score,white.score, white.name, "(White)");

    fclose(fp);
}