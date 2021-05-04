//
// Created by J on 27/04/2021.
//

#include "library.h"
#include <stdio.h>

/* This function prints the results & appends the results to the file "othello_results.txt" */
void printWinner(char startTime[])
{
    int difference = black.score - white.score;

    //open file for appending
    FILE *fp;
    fp = fopen("othello_results.txt","w");

    puts("\n\n\n\nGame Completed");
    fprintf(fp,"%s %s\n","Game start time:",startTime);         //add the game start time to the file


    //add the winner of the game to the file
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

    //print the final state of the board
    puts("Final Board:");
    printBoard();

    //add the final state of the board to the file
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