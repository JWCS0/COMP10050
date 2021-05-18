//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

/* This function sets up the game to be ready to play */
void initializeGame()
{
    extern enum piece currPlayer;

    //get the player names
    char player1[PLAYER_NAME_LEN];
    char player2[PLAYER_NAME_LEN];

    //Get player names
    puts("Player 1 Name (Black):");
    scanf("%s19",player1);
    puts("Player 2 Name (White):");
    scanf("%s19",player2);

    strcpy(black.name,player1);
    strcpy(white.name,player2);

    //set starting player
    currPlayer = BLACK;

    //fill board with "empty" squares
    for (size_t i = 1; i < 9; i++) {
        for (size_t j = 1; j < 9; j++) {
            board[j][i].square = EMPTY;
        }
    }

    //set the starting pieces
    board[4][4].square = WHITE;
    board[4][5].square = BLACK;
    board[5][4].square = BLACK;
    board[5][5].square = WHITE;

    //set the top-most and bottom-most rows as "end of board" squares
    for (size_t i = 0; i < 10; i+=9) {
        for (size_t j = 0; j < 10; j++) {
            board[i][j].square = EOB;
        }
    }

    //set the left-most and right-most rows as "end of board" squares
    for (size_t i = 0; i < 10; i+=9) {
        for (size_t j = 0; j < 10; j++) {
            board[j][i].square = EOB;
        }
    }

    //set the x and y offsets for the 8 ordinal direction in the directions structs array
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

    //initialise score & player colors
    black.score = 2;
    black.color = BLACK;
    white.score = 2;
    white.color = WHITE;
}