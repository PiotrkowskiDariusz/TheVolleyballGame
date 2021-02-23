#include "Team.h"

Team::Team(QString name) {
    this->name = name;
    this->points = 0;
}

QList<Player *> &Team::getPlayers() {
    return this->players;
}

int Team::getPoints() {
    return this->points;
}

void Team::setPoints(int points) {
    this->points = points;
}

QString Team::getName() {
    return this->name;
}
