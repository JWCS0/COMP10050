//
// Created by J on 16/04/2021.
//

#include <stdio.h>
#include <ctype.h>
#include "library.h"

int findValidMoves(char choice[], enum piece player)
{
    printf("CHOICE %s\n\n",choice);
    int validMoves = 0;
    int change;

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
            printf("\nOrigin %d %d\n",row, column);
            printf("Direction %d %d\n",rowOffset,colOffset);
            while (board[row+rowOffset][column+colOffset].square != EOB) {
                printf("Square type %d @ pos %d %d\n",board[row+rowOffset][column+colOffset].square,
                       row+rowOffset,column+colOffset);
                printf("Prev square %d %d\n",row+rowOffset+(ordDirections[i].xMod*-1),column+colOffset+(ordDirections[i].yMod*-1));
                if (board[row+rowOffset][column+colOffset].square == player &&
                    board[row+rowOffset+(ordDirections[i].xMod*-1)][column+colOffset+(ordDirections[i].yMod*-1)].square == opposite) {
                    puts("True");
                    change = capture(row+rowOffset,column+colOffset,i,player);
                    switch(player) {
                        case BLACK:
                            black.score += change+1;
                            white.score -= change;
                            break;
                        case WHITE:
                            black.score += change;
                            white.score -= change+1;
                            break;
                        default:
                            continue;
                    }
                    validMoves++;
                }
                else if (board[row+rowOffset][column+colOffset].square == EMPTY &&
                board[row+rowOffset+(ordDirections[i].xMod*-1)][column+colOffset+(ordDirections[i].yMod*-1)].square == EMPTY){
                    puts("break");
                    break;
                }
                rowOffset += ordDirections[i].xMod;
                colOffset += ordDirections[i].yMod;
            }
        }
    }

    return validMoves;
}