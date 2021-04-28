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
        printf("%s %s","Winner is (black)",black.name);
        fprintf(fp,"%s %s\n","Winner is (black)",black.name);
    }
    else if (difference < 0) {
        printf("%s %s","Winner is (white)", white.name);
        fprintf(fp,"%s %s\n","Winner is (white)",white.name);
    }
    else {
        printf("%s","Game ended in a draw");
        fprintf(fp,"%s\n","Game ended in a draw");
    }

    fprintf(fp,"%s\n","Result:");
    fprintf(fp,"%s %s %d : %d %s %s","(Black)",black.name,black.score,white.score, white.name, "(White)");

    fclose(fp);
}