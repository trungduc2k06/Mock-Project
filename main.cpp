#include "Controller.h"

int main()
{
    Game* game = new Game(BOARD_SIZE);
    View* view = new View;
    Controller* controller = new Controller(game, view);
    controller->startGame();
    return 0;
}