#include <stdio.h>
#include "library.h"

int gameFinish = 0;

int main()
{

    initializeGame();
    printBoard();


    while (gameFinish != 1) {
        turnAction();
        puts("next player");
    }
}
