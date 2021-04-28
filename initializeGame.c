//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "library.h"

void initializeGame()
{
    extern enum piece currPlayer;
    char startingPlayer;

    char player1[PLAYER_NAME_LEN];
    char player2[PLAYER_NAME_LEN];
    //Get player names
    puts("Player 1 Name (Black):");
    scanf("%s19",player1);
    puts("Player 2 Name (White):");
    scanf("%s19",player2);

    strcpy(black.name,player1);
    strcpy(white.name,player2);

    //choose starting player
    do {
        puts("Which player is first (b/w)? Enter (r) for random");
        scanf("\n%c", &startingPlayer);
        if (tolower(startingPlayer) == 'b') {
            currPlayer = BLACK;
            break;
        }
        else if (tolower(startingPlayer) == 'w') {
            currPlayer = WHITE;
            break;
        }
        else if (tolower(startingPlayer) == 'r') {
            int num;
            srand(time(NULL));
            num = rand()%2;
            if (num == 0){
                currPlayer = BLACK;
            }
            else {
                currPlayer = WHITE;
            }
            break;
        }
        puts("Invalid input");
    } while (1);


    for (size_t i = 1; i <= 9; i++) {
        for (size_t j = 1; j <= 9; j++) {
            board[j][i].square = EMPTY;
        }
    }

    board[4][4].square = WHITE;
    board[4][5].square = BLACK;
    board[5][4].square = BLACK;
    board[5][5].square = WHITE;

    for (size_t i = 0; i < 10; i+=9) {
        for (size_t j = 0; j < 10; j++) {
            board[i][j].square = EOB;
        }
    }
    for (size_t i = 0; i < 10; i+=9) {
        for (size_t j = 0; j < 10; j++) {
            board[j][i].square = EOB;
        }
    }

    int x = 0;
    for (int i = -1; i <=1; i++) {
        for (int j = -1; j <=1; j++){
            if (i==0 && j==0) {
                continue;
            }
            else {
                ordDirections[x].xMod = j;
                ordDirections[x++].yMod = i;
            }
        }
    }

    black.score = 2;
    black.color = BLACK;
    white.score = 2;
    white.color = WHITE;
}