//
// Created by J on 16/04/2021.
//

#ifndef ASSIGNMENT_2_LIBRARY_H
#define ASSIGNMENT_2_LIBRARY_H
#define PLAYER_NAME_LEN 20


enum piece {EMPTY, BLACK, WHITE, EOB};

struct position
{
    enum piece square;
} board[10][10];

struct player
{
    enum piece color;
    int score;
    char name[PLAYER_NAME_LEN];
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
int findValidMoves(char choice[], enum piece player, int onlyCheck);
int capture(int row, int column, int direction, enum piece type);
int movesAvailable(enum piece player);
void printWinner(char startTime[]);

#endif //ASSIGNMENT_2_LIBRARY_H
