//
// Created by J on 16/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H


enum piece {EMPTY, BLACK, WHITE};
enum column {A ,B ,C ,D ,E ,F ,G ,H};

struct position
{
    enum piece square;
} board[8][8];

struct player
{
    enum piece piece;
    int score;
} black, white;

/* Function Prototypes */
void initializeBoard();
void printBoard();
void turnAction();
int isValidMove(char choice[], int player);

#endif //ASSIGNMENT_2_LIBRARY_H
