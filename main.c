#include <stdio.h>
#include "library.h"

int gameFinish = 0;

int main()
{

    initializeBoard();
    printBoard();

    while (gameFinish != 1) {
        turnAction();
    }
}
