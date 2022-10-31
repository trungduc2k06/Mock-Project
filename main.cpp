#include "Board.h"
#include "View.h"

int main()
{
    Game* game = new Game(BOARD_SIZE);
    View view;
    view.startGame();
    return 0;
}