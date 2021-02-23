#include "Object.h"
#include "Game.h"
#include "Ball.h"
#include "RightHitter.h"
#include "Setter.h"
#include "Receiver.h"

extern Game * game;

Object::Object(LogicObject *logicObject, QString path) {
    this->logicObject = logicObject;
    this->path = path;
}

LogicObject *Object::getLogicObject() {
    return this->logicObject;
}

void Object::draw() {
    QImage object = QImage(path);
    QPixmap qPixMap = QPixmap::fromImage(object);
    qPixMap = qPixMap.scaled(logicObject->getWidth(), logicObject->getHeight());
    setPixmap(qPixMap);
    this->setPos(logicObject->getX(), logicObject->getY());
    this->setVisible(true);
    game->scene->addItem(this);
}
