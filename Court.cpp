#include "Court.h"
#include "Setter.h"
#include "RightHitter.h"
#include "Receiver.h"

Court::Court(int height, int width, bool actionInProgress) {
    this->height = height;
    this->width = width;
    this->actionInProgress = actionInProgress;
    this->out = false;
    this->served = true;
}

void Court::makeTeam(QString name, int number) {
    if (number == 1) {
        this->team1 = new Team(name);

        this->team1->getPlayers().append(new RightHitter(300, 40, 40, 40, this, this->team1));
        this->team1->getPlayers().append(new Setter(300, 190, 40, 40, this, this->team1));
        this->team1->getPlayers().append(new RightHitter(300, 350, 40, 40, this, this->team1));
        this->team1->getPlayers().append(new Receiver(100, 40, 40, 40, this, this->team1));
        this->team1->getPlayers().append(new Receiver(100, 190, 40, 40, this, this->team1));
        this->team1->getPlayers().append(new Receiver(100, 350, 40, 40, this, this->team1));
        for (int i = 0; i < this->team1->getPlayers().length(); i++){
            this->objects.append(this->team1->getPlayers()[i]);
        }
    }
    else if (number == 2) {
        this->team2 = new Team(name);

        this->team2->getPlayers().append(new RightHitter(450, 40, 40, 40, this, this->team2));
        this->team2->getPlayers().append(new Setter(450, 190, 40, 40, this, this->team2));
        this->team2->getPlayers().append(new RightHitter(450, 350, 40, 40, this, this->team2));
        this->team2->getPlayers().append(new Receiver(650, 40, 40, 40, this, this->team2));
        this->team2->getPlayers().append(new Receiver(650, 190, 40, 40, this, this->team2));
        this->team2->getPlayers().append(new Receiver(650, 350, 40, 40, this, this->team2));
        for (int i = 0; i < this->team2->getPlayers().length(); i++){
            this->objects.append(this->team2->getPlayers()[i]);
        }
    }

}

void Court::makeBall(int x, int y, int height, int width) {
    this->ball = new Ball(x, y, height, width, this, 2, this->team1->getPlayers()[0]);
    this->objects.append(this->ball);
}

LogicObject *Court::getBall() {
    return this->ball;
}

int Court::getHeight() {
    return this->height;
}

void Court::setHeight(int height) {
    this->height = height;
}

int Court::getWidth() {
    return this->width;
}

void Court::setWidth(int width) {
    this->width = width;
}

bool Court::getActionInProgress()
{
    return this->actionInProgress;
}

void Court::setActionInProgress(bool actionInProgress)
{
    this->actionInProgress = actionInProgress;
}

bool Court::getServed()
{
    return this->served;
}

void Court::setServed(bool served)
{
    this->served = served;
}

bool Court::getOut() {
    return this->out;
}

void Court::setOut(bool out) {
    this->out = out;
}

QList<LogicObject *> &Court::getObjects() {
    return this->objects;
}

Team *Court::getTeam1() {
    return this->team1;
}

Team *Court::getTeam2() {
    return this->team2;
}
