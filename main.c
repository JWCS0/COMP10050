#include "library.h"

int gameFinish = 0;
enum piece currPlayer;

int main()
{
    initializeGame();
    printBoard();

    while (gameFinish != 1) {
        turnAction();
    }

    printWinner();
}
