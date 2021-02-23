#include "LogicObject.h"

LogicObject::LogicObject(int startX, int startY, int height, int width, Court *court) {
    this->x = startX;
    this->y = startY;
    this->startX = startX;
    this->startY = startY;
    this->height = height;
    this->width = width;
    this->court = court;
    this->targetX = 1;
    this->targetY = 1;
}

int LogicObject::getX() {
    return this->x;
}

int LogicObject::getStartX() {
    return startX;
}

int LogicObject::getY() {
    return this->y;
}

int LogicObject::getStartY() {
    return startY;
}

int LogicObject::getHeight() {
    return this->height;
}

int LogicObject::getWidth() {
    return this->width;
}

int LogicObject::getDirection() {
    return this->direction;
}

int LogicObject::getTargetX() {
    return this->targetX;
}

int LogicObject::getTargetY()
{
    return this->targetY;
}

LogicObject *LogicObject::getParent() {
    return this->parent;
}

Court *LogicObject::getCourt() {
    return this->court;
}

void LogicObject::setX(int x) {
    this->x = x;
}

void LogicObject::setY(int y) {
    this->y = y;
}

void LogicObject::setHeight(int height) {
    this->height = height;
}

void LogicObject::setWidth(int width) {
    this->width = width;
}

void LogicObject::setDirection(int direction) {
    this->direction = direction;
}

void LogicObject::setTargetX(int x) {
    this->targetX = x;
}

void LogicObject::setTargetY(int y) {
    this->targetY = y;
}

void LogicObject::setParent(LogicObject *parent) {
    this->parent = parent;
}

LogicObject *LogicObject::getLogicObject() {
    return this;
}
