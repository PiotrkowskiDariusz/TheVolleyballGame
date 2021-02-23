#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "Object.h"
#include "Court.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    /// \brief timer
    /// \details Zmienna odliczająca czas
    QTimer *timer;
    /// \brief score1
    /// \details Wynik drużyny 1
    QGraphicsTextItem *score1;
    /// \brief score2
    /// \details Wynik drużyny 2
    QGraphicsTextItem *score2;
    /// \brief court
    /// \details Wskaźnik do boiska
    Court *court;
    /// \brief objects
    /// \details Wskaźnik do listy obiektów graficznych
    QList<Object *> objects;
    /// \brief scene
    /// \details Wskaźnik sceny
    QGraphicsScene * scene;
    Game();
    /// \brief buildObjects
    /// \details Dodawanie obiektów graficznych do listy
    void buildObjects();
public slots:
    /// \brief setObjectsOnScene
    /// \details Ustawianie obiektów graficznych na scenie
    void setObjectsOnScene();
    /// \brief step
    /// \details Wykonanie kolejnego kroku w grze
    void step();
};

#endif // GAME_H


// gra i obiekt graficzny moga miec graficzne elementy
