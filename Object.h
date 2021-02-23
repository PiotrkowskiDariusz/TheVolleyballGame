#ifndef OBJECT_H
#define OBJECT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "LogicObject.h"

using namespace std;

class Object: public  QObject, public QGraphicsPixmapItem {
private:
    /// \brief logicObject
    /// \details Wskaźnik na odpowiadający obiekt logiczny
    LogicObject *logicObject;
    /// \brief path
    /// \details Ścieżka do pliku przechowującego grafikę
    QString path;
public:
    Object(LogicObject *logicObject, QString path);
    /// \brief getLogicObject
    /// \details Zwraca wskaźnik na odpowiadający obiekt logiczny
    LogicObject *getLogicObject();
    /// \brief draw
    /// \details Funkcja rysująca obiekty graficzne na scenie
    void draw();
};

#endif // OBJECT_H
