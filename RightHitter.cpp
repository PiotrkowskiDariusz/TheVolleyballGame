#include "RightHitter.h"
#include "Court.h"
#include "Setter.h"

void RightHitter::attack() {
    srand(time(NULL));
    int d = rand()%2;
    int tx = 0;
    int ty = 0;
    if (this->getX() < 400){
        if (this->getY() < 200) {
            if (d == 0) {
                this->getCourt()->getBall()->setDirection(2);
                tx = rand()%380 + 520; // 520-900
                ty = rand()%130; // 0-130
            }
            else if (d == 1) {
                this->getCourt()->getBall()->setDirection(6);
                tx = rand()%380 + 520; // 520-900
                ty = rand()%370 + 130; // 130-500
            }
        }
        if (this->getY() > 200) {
            if (d == 0) {
                this->getCourt()->getBall()->setDirection(2);
                tx = rand()%380 + 520; // 520-900
                ty = rand()%140 + 260; // 260-400
            }
            else if (d == 1) {
                this->getCourt()->getBall()->setDirection(7);
                tx = rand()%380 + 520; // 520-900
                ty = rand()%260; // 0-260
            }
        }
    }
    else if (this->getX() > 400){
        if (this->getY() < 200) {
            if (d == 0) {
                this->getCourt()->getBall()->setDirection(3);
                tx = rand()%280; // 0-280
                ty = rand()%130; // 0-130
            }
            else if (d == 1) {
                this->getCourt()->getBall()->setDirection(8);
                tx = rand()%280; // 0-280
                ty = rand()%370 + 130; // 130 - 500
            }
        }
        if (this->getY() > 200) {
            if (d == 0) {
                this->getCourt()->getBall()->setDirection(3);
                tx = rand()%280; // 0-280
                ty = rand()%140 + 260; // 260-400
            }
            else if (d == 1) {
                this->getCourt()->getBall()->setDirection(9);
                tx = rand()%280; // 0-280
                ty = rand()%260; // 0-260
            }
        }
    }
    this->getCourt()->getBall()->setParent(this);
    this->getCourt()->getBall()->setTargetX(tx);
    this->getCourt()->getBall()->setTargetY(ty);
    this->getCourt()->setServed(false);
    this->setX(this->getStartX());
    this->setY(this->getStartY());
}

void RightHitter::update() {
    for (int i = 0; i < this->getCourt()->getObjects().length(); i++) {
        LogicObject *collidingObject = this->getCourt()->getObjects()[i];

        Ball* ball = dynamic_cast<Ball *>(collidingObject);
        Setter* setter = dynamic_cast<Setter *>(this->getCourt()->getBall()->getParent());
        if (setter) {
            if (ball) {
                if (((collidingObject) != this) && ((collidingObject)->getWidth() + (collidingObject)->getX() >= this->getX()) && ((collidingObject)->getX() <= this->getWidth() + this->getX()) && ((collidingObject)->getY() + (*collidingObject).getHeight() >= this->getY()) && ((collidingObject)->getY() <= this->getY() + this->getHeight())) {
                    this->attack();
                }
                else if((this->getCourt()->getBall()->getParent() != this) && (collidingObject != this) && (collidingObject->getWidth() + collidingObject->getX() >= this->getX() - 50) && (collidingObject->getX() <= this->getWidth() + this->getX() + 50) && (collidingObject->getY() + collidingObject->getHeight() >= this->getY() - 50) && (collidingObject->getY() <= this->getY() + this->getHeight() + 50)) {
                    this->move();
                }
            }
        }
    }
}
