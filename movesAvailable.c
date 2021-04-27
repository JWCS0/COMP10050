//
// Created by J on 25/04/2021.
//

#include "library.h"

int movesAvailable(enum piece player)
{
    char position[3];
    int validMoves = 0;

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            if (board[i][j].square == EMPTY) {
                position[0] = 'a'+i-1;
                position[1] = '0'+j;
                validMoves += findValidMoves(position,player,1);
            }
        }
    }
    return validMoves;
}