#ifndef BALL_H
#define BALL_H
#include "Object.h"
#include "Player.h"

class Ball: public LogicObject {
public:
    Ball(int x, int y, int height, int width, Court *court, int direction, LogicObject *parent);
    /// \brief update
    /// \details Sprawdzenie pozycji piłki, zmiana współrzędnych
    virtual void update();

};

#endif // BALL_H
