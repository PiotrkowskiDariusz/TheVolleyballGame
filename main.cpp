#include "Game.h"
#include <QApplication>

Game *game;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    game = new Game();
    game->buildObjects();
    game->show();
    return a.exec();
}
