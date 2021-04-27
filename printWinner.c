//
// Created by J on 27/04/2021.
//

#include "library.h"
#include <stdio.h>

void printWinner()
{
    int difference = black.score - white.score;

    FILE *fp;
    fp = fopen("results.txt","w");

    if (difference > 0) {
        printf("%s","Winner is black");
        fprintf(fp,"%s\n","Winner is black");
    }
    else if (difference < 0) {
        printf("%s","Winner is white");
        fprintf(fp,"%s\n","Winner is white");
    }
    else {
        printf("%s","Game ended in a draw");
        fprintf(fp,"%s\n","Game ended in a draw");
    }

    fprintf(fp,"%s\n","Result:");
    fprintf(fp,"%s %d : %d %s","Black",black.score,white.score, "White");

    fclose(fp);
}