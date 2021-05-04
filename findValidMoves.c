//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <ctype.h>
#include "library.h"
#include <string.h>

/* This function returns whether there is a position is a valid move for the player */
int findValidMoves(char choice[], enum piece player, int onlyCheck)
{
    int validMoves = 0;
    int change = 0;

    printf("Checking %s\n",choice);
    if (strcmp(choice,"h7")==0) {
        puts("here");
    }

    //convert the character into integers
    int column = tolower(choice[0]-'a')+1;
    int row = tolower(choice[1]-'0'-1)+1;

    enum piece opposite;                        //variable to store the opposite piece color

    //set the opposite piece color
    switch (player) {
        case BLACK:
            opposite = WHITE;
            break;
        case WHITE:
            opposite = BLACK;
            break;
        default:
            puts("");
            break;
    }

    //check the input is in range (a-h, 1,8)
    if (column < 9 && column > 0 && row < 9 && row > 0 && board[row][column].square == EMPTY){

        //loop through all 8 of the ordinal directions
        for (size_t i = 0; i < 8; i++) {

            //set the x and y offsets
            int rowOffset = ordDirections[i].xMod;
            int colOffset = ordDirections[i].yMod;

            //loop in direction until the current position has the same piece as the current player
            while (board[row+rowOffset][column+colOffset].square != player) {

                //if the current position has the opposite piece, change the position by the offset
                if (board[row+rowOffset][column+colOffset].square == opposite) {
                    rowOffset += ordDirections[i].xMod;
                    colOffset += ordDirections[i].yMod;
                }

                //if the current position is empty/end of board is reached, break out of loop
                else if (board[row+rowOffset][column+colOffset].square == EMPTY ||
                        board[row+rowOffset][column+colOffset].square == EOB){
                    break;
                }
            }

            //check if the current position has the current player's piece and the previous piece is the opposite color
            if (board[row+rowOffset][column+colOffset].square == player &&
                board[row+rowOffset+(ordDirections[i].xMod*-1)][column+colOffset+(ordDirections[i].yMod*-1)].square == opposite) {

                //call capture function if not only checking for valid moves
                if (onlyCheck != 1) {
                    change += capture(row+ordDirections[i].xMod,column+ordDirections[i].yMod,i,player);
                }
                validMoves = 1;
            }
        }

        //complete capture if there is < 0 valid moves and not only checking for valid moves
        if (validMoves != 0 && onlyCheck != 1) {
            board[row][column].square = player;
            switch(player) {
                case BLACK:
                    black.score += change+1;
                    white.score -= change;
                    break;
                case WHITE:
                    black.score -= change;
                    white.score += change+1;
                    break;
                default:
                    break;
            }
        }
    }

    return validMoves;
}