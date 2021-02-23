#include "Player.h"
#include "Team.h"
#include "Court.h"

Player::Player(int x, int y, int height, int width, Court *court, Team *team):LogicObject(x, y, height, width, court) {
    this->team = team;
}

Team *Player::getTeam()
{
    return this->team;
}

void Player::move() {
    if (this->getX() < this->getCourt()->getBall()->getX()) {
        this->setX(this->getX()+25);
    }
    if (this->getX() > this->getCourt()->getBall()->getX()) {
        this->setX(this->getX()-25);
    }
    if (this->getY() < this->getCourt()->getBall()->getY()) {
        this->setY(this->getY()+25);
    }
    if (this->getY() > this->getCourt()->getBall()->getY()) {
        this->setY(this->getY()-25);
    }
}
