#include "Receiver.h"
#include "Court.h"
#include "RightHitter.h"
#include <windows.h>

void Receiver::receive() {
    if (this->getX() < 400){
        if (this->getY() > 150 && this->getY() < 250)
            this->getCourt()->getBall()->setDirection(2);
        else if (this->getY() < 150)
            this->getCourt()->getBall()->setDirection(6);
        else if (this->getY() > 250)
            this->getCourt()->getBall()->setDirection(7);
    }
    else if (this->getX() > 400){
        if (this->getY() > 150 && this->getY() < 250)
            this->getCourt()->getBall()->setDirection(3);
        else if (this->getY() < 150)
            this->getCourt()->getBall()->setDirection(8);
        else if (this->getY() > 250)
            this->getCourt()->getBall()->setDirection(9);
    }
    this->getCourt()->getBall()->setParent(this);
    this->getCourt()->setServed(false);
    this->getCourt()->getBall()->setTargetX(0);
    this->getCourt()->getBall()->setTargetY(0);
    this->setX(this->getStartX());
    this->setY(this->getStartY());
}

void Receiver::serve()
{
    for(int i = 0; i < this->getCourt()->getObjects().length(); i++) {
        this->getCourt()->getObjects()[i]->setX(this->getCourt()->getObjects()[i]->getStartX());
        this->getCourt()->getObjects()[i]->setY(this->getCourt()->getObjects()[i]->getStartY());
    }

    srand(time(NULL));
    int d = rand() % 2;

    Player *player = (Player *)this->getCourt()->getBall()->getParent();

    if((player->getTeam() == this->getCourt()->getTeam1() && this->getCourt()->getOut() == false) || (player->getTeam() == this->getCourt()->getTeam2() && this->getCourt()->getOut() == true)) {
        if (this->getStartX() < 400 && this->getStartY() > 300) {
            this->setX(50);
            this->setY(350);
            this->getCourt()->getBall()->setX(70);
            this->getCourt()->getBall()->setY(350);
            if (d == 0)
                this->getCourt()->getBall()->setDirection(2);
            else if (d == 1)
                this->getCourt()->getBall()->setDirection(10);
            this->getCourt()->setServed(true);
            this->getCourt()->getBall()->setParent(this);
            this->getCourt()->setActionInProgress(true);
            this->getCourt()->setOut(false);
            Sleep(1000);
        }
    }
    else if ((player->getTeam() == this->getCourt()->getTeam2() && this->getCourt()->getOut() == false) || (player->getTeam() == this->getCourt()->getTeam1() && this->getCourt()->getOut() == true)) {
        if (this->getStartX() > 400 && this->getStartY() < 50) {
            this->setX(760);
            this->setY(50);
            this->getCourt()->getBall()->setX(740);
            this->getCourt()->getBall()->setY(50);
            if (d == 0)
                this->getCourt()->getBall()->setDirection(3);
            else if (d == 1)
                this->getCourt()->getBall()->setDirection(11);
            this->getCourt()->setServed(true);
            this->getCourt()->getBall()->setParent(this);
            this->getCourt()->setActionInProgress(true);
            this->getCourt()->setOut(false);
            Sleep(1000);
        }
    }

    this->getCourt()->getBall()->setTargetX(0);
    this->getCourt()->getBall()->setTargetY(0);    
    this->setX(this->getStartX());
    this->setY(this->getStartY());
}

void Receiver::update() {
    for (int i = 0; i < this->getCourt()->getObjects().length(); i++) {
        LogicObject *collidingObject = this->getCourt()->getObjects()[i];

        Ball* ball = dynamic_cast<Ball *>(collidingObject);

        if (ball) {
            RightHitter *rh = dynamic_cast<RightHitter *>(this->getCourt()->getBall()->getParent());
            if ((rh || this->getCourt()->getServed() == true) && this->getCourt()->getActionInProgress() == true && this->getCourt()->getBall()->getParent() != this) {
                if (((collidingObject) != this) && ((collidingObject)->getWidth() + (collidingObject)->getX() >= this->getX()) && ((collidingObject)->getX() <= this->getWidth() + this->getX()) && ((collidingObject)->getY() + (*collidingObject).getHeight() >= this->getY()) && ((collidingObject)->getY() <= this->getY() + this->getHeight())) {
                    if(this->getCourt()->getOut() == false) {
                        this->receive();
                    }
                }
                else if((this->getCourt()->getBall()->getParent() != this) && (collidingObject != this) && (collidingObject->getWidth() + collidingObject->getX() >= this->getX() - 50) && (collidingObject->getX() <= this->getWidth() + this->getX() + 50) && (collidingObject->getY() + collidingObject->getHeight() >= this->getY() - 50) && (collidingObject->getY() <= this->getY() + this->getHeight() + 50)) {
                    if (this->getCourt()->getOut() == false) {
                        this->move();
                    }
                }
            }
        }

        if (this->getCourt()->getActionInProgress() == false) {
            this->serve();
        }
    }
}

// 6 - prawo dol, 7 - prawo gora, 8 - lewo dol, 9 - lewo gora
