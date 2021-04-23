//
// Created by J on 16/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H


enum piece {EMPTY, BLACK, WHITE, EOB};
enum column {a ,b ,c ,d ,e ,f ,g ,h};
enum direction {NW, N, NE, W, E, SW, S, SE};

struct position
{
    enum piece square;
} board[10][10];

struct player
{
    enum piece color;
    int score;
} black, white;

struct ordinalDir
{
    int xMod;
    int yMod;
} ordDirections[8];

/* Function Prototypes */
void initializeGame();
void printBoard();
void turnAction();
int isValidMove(char choice[], enum piece player);
int search(int row, int column, enum direction choice);

#endif //ASSIGNMENT_2_LIBRARY_H
