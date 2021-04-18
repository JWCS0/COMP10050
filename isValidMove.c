//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <ctype.h>
#include "library.h"

int isValidMove(char choice[], int player)
{
    //convert the character into integers
    int column = tolower(choice[0]-'a');
    int row = tolower(choice[1]-'0'-1);

    //check the input is in range (a-h, 1,8)
    if (column < 8 && column >= 0 && row < 8 && row >= 0 && board[row][column].square != player){
        for (size_t i = row-1; i < row+2; i++) {
            for (size_t j = column-1; j < column+2; j++) {
                if (!(i == row && j == column)) {
                    if (board[i][j].square != player && board[i][j].square != EMPTY){
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}