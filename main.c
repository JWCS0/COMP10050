#include "library.h"
#include <stdio.h>
#include <time.h>

int gameFinish = 0;
enum piece currPlayer;


int main()
{
    //https://stackoverflow.com/questions/5141960/get-the-current-time-in-c
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );

    puts("\t*** Welcome to Othello!! ***");
    initializeGame();
    printBoard();

    while (gameFinish != 1) {
        turnAction();
    }

    printWinner(asctime (timeinfo));
}
