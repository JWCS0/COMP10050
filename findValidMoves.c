//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <ctype.h>
#include "library.h"

int findValidMoves(char choice[], enum piece player, int onlyCheck)
{
    int validMoves = 0;
    int change = 0;

    //convert the character into integers
    int column = tolower(choice[0]-'a')+1;
    int row = tolower(choice[1]-'0'-1)+1;

    enum piece opposite;

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
        for (size_t i = 0; i < 8; i++) {
            int rowOffset = ordDirections[i].xMod;
            int colOffset = ordDirections[i].yMod;

            while (board[row+rowOffset][column+colOffset].square != player) {
                if (board[row+rowOffset][column+colOffset].square == opposite) {
                    rowOffset += ordDirections[i].xMod;
                    colOffset += ordDirections[i].yMod;
                }
                else if (board[row+rowOffset][column+colOffset].square == EMPTY ||
                        board[row+rowOffset][column+colOffset].square == EOB){
                    break;
                }
            }

            if (board[row+rowOffset][column+colOffset].square == player &&
                board[row+rowOffset+(ordDirections[i].xMod*-1)][column+colOffset+(ordDirections[i].yMod*-1)].square == opposite) {
                if (onlyCheck != 1) {
                    change += capture(row+ordDirections[i].xMod,column+ordDirections[i].yMod,i,player);
                }
                validMoves = 1;
            }
        }

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