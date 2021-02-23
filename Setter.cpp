#include "Setter.h"
#include "Court.h"
#include "Receiver.h"

void Setter::set() {
    srand(time(NULL));
    int d = rand() % 2;
    if (d == 0) {
        this->getCourt()->getBall()->setDirection(4);
    }
    else if (d == 1) {
        this->getCourt()->getBall()->setDirection(5);
    }

    this->getCourt()->getBall()->setParent(this);
    this->getCourt()->getBall()->setTargetX(0);
    this->getCourt()->getBall()->setTargetY(0);
    this->getCourt()->setServed(false);
    this->getCourt()->setOut(false);
    this->setX(this->getStartX());
    this->setY(this->getStartY());
}

void Setter::update() {
    for (int i = 0; i < this->getCourt()->getObjects().length(); i++) {
        LogicObject *collidingObject = this->getCourt()->getObjects()[i];

        Ball* ball = dynamic_cast<Ball *>(collidingObject);

        if (ball) {
            Receiver *r = dynamic_cast<Receiver *>(this->getCourt()->getBall()->getParent());
            if (r && this->getCourt()->getServed() == false) {
                if (((collidingObject) != this) && ((collidingObject)->getWidth() + (collidingObject)->getX() >= this->getX()) && ((collidingObject)->getX() <= this->getWidth() + this->getX()) && ((collidingObject)->getY() + (*collidingObject).getHeight() >= this->getY()) && ((collidingObject)->getY() <= this->getY() + this->getHeight())) {
                    this->set();
                }
                else if((this->getCourt()->getBall()->getParent() != this) && (collidingObject != this) && (collidingObject->getWidth() + collidingObject->getX() >= this->getX() - 50) && (collidingObject->getX() <= this->getWidth() + this->getX() + 50) && (collidingObject->getY() + collidingObject->getHeight() >= this->getY() - 50) && (collidingObject->getY() <= this->getY() + this->getHeight() + 50)) {
                    this->move();
                }
            }
        }
    }
}
