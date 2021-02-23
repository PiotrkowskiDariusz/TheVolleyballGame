#include "Ball.h"
#include "Court.h"
#include "RightHitter.h"
#include "Setter.h"
#include "Player.h"

Ball::Ball(int x, int y, int height, int width, Court *court, int direction, LogicObject *parent):LogicObject(x, y, height, width, court) {
    this->setDirection(direction);
    this->setParent(parent);
}

void Ball::update() {
    if (this->getTargetX() < 0 || this->getTargetX() > this->getCourt()->getHeight() || this->getTargetY() < 0 || this->getTargetY() > this->getCourt()->getWidth()) {
        this->getCourt()->setOut(true);
    }

    if (this->getX() < 0 || this->getX() > this->getCourt()->getHeight() || this->getY() < 0 || this->getY() > this->getCourt()->getWidth()) {
        this->getCourt()->setActionInProgress(false);
        if (this->getX() > this->getCourt()->getHeight()/2) {
            this->getCourt()->getTeam2()->setPoints(this->getCourt()->getTeam2()->getPoints()+1);
        }
        else if (this->getX() < this->getCourt()->getHeight()/2) {
            this->getCourt()->getTeam1()->setPoints(this->getCourt()->getTeam1()->getPoints()+1);
        }
    }

    if ((abs(this->getX() - this->getTargetX()) <= 60 && abs(this->getY() - this->getTargetY()) <= 60) && this->getCourt()->getActionInProgress() == true) {
        this->getCourt()->setActionInProgress(false);

        if (this->getTargetX() > this->getCourt()->getHeight()/2) {
            this->getCourt()->getTeam1()->setPoints(this->getCourt()->getTeam1()->getPoints()+1);
        }
        else if (this->getTargetX() < this->getCourt()->getHeight()/2) {
            this->getCourt()->getTeam2()->setPoints(this->getCourt()->getTeam2()->getPoints()+1);
        }
    }

    RightHitter *rh = dynamic_cast<RightHitter *>(this->getParent());
    Setter *s = dynamic_cast<Setter *>(this->getParent());
    int change = 15;
    if(rh){
        change = 25;
    }
    else if (s) {
        change = 10;
    }

    if (this->getDirection() == 2) {
        this->setX(this->getX()+change);
    }
    else if (this->getDirection() == 3) {
        this->setX(this->getX()-change);
    }
    else if (this->getDirection() == 4) {
        this->setY(this->getY()+change);
    }
    else if (this->getDirection() == 5) {
        this->setY(this->getY()-change);
    }
    else if (this->getDirection() == 6) {
        this->setX(this->getX()+change);
        this->setY(this->getY()+0.75*change);
    }
    else if (this->getDirection() == 7) {
        this->setX(this->getX()+change);
        this->setY(this->getY()-0.75*change);
    }
    else if (this->getDirection() == 8) {
        this->setX(this->getX()-change);
        this->setY(this->getY()+0.75*change);
    }
    else if (this->getDirection() == 9) {
        this->setX(this->getX()-change);
        this->setY(this->getY()-0.75*change);
    }
    else if (this->getDirection() == 10) {
        this->setX(this->getX()+change);
        this->setY(this->getY()-0.3*change);
    }
    else if (this->getDirection() == 11) {
        this->setX(this->getX()-change);
        this->setY(this->getY()+0.3*change);
    }
}


// 2 - w prawo, 3 - w lewo, 4 - dol, 5 - gora
// 6 - prawo dol, 7 - prawo gora, 8 - lewo dol, 9 - lewo gora, 10 - prawo gora serw, 11 - lewo dol serw
