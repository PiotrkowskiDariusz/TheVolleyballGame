#ifndef COURT_H
#define COURT_H

#include <QList>
#include "LogicObject.h"
#include "Team.h"
#include "Ball.h"

class Court {
private:
    /// \brief height
    /// \details Wysokosc boiska
    int height;
    /// \brief width
    /// \details Szerokosc boiska
    int width;
    /// \brief objects
    /// \details Lista obiektów graficznych znajdyjących się na boisku
    QList <LogicObject *> objects;
    /// \brief ball
    /// \details Obiekt reprezentujący piłkę
    LogicObject *ball;
    /// \brief team1
    /// \details Drużyna pierwsza
    Team *team1;
    /// \brief team2
    /// \details Drużyna druga
    Team *team2;
    /// \brief actionInProgress
    /// \details Zmienna informująca czy toczy się akcja
    bool actionInProgress;
    /// \brief served
    /// \details Zmienna informująca czy piłka została dopiero co zaserwowana
    bool served;
    /// \brief out
    /// \details Zmienna informująca czy piłka wyszła na out
    bool out;
public:
    Court(int height, int width, bool actionInProgress);
    /// \brief makeTeam
    /// \details Tworzenie druzyny
    /// \param name nazwa drużyny
    /// \param number numer drużyny
    void makeTeam(QString name, int number);
    /// \brief makeBall
    /// \details Tworzenie piłki
    /// \param x współrzędna x piłki
    /// \param y współrzędna y piłki
    /// \param height wsyokość obiektu
    /// \param width szerokosc obiektu
    void makeBall(int x, int y, int height, int width);
    /// \brief getBall
    /// \details Zwraca wskaźnik do piłki
    LogicObject *getBall();
    /// \brief getHeight
    /// \details Zwraca szerokość boiska
    int getHeight();
    /// \brief setHeight
    /// \details Ustawia wysokosc boiska
    /// \param height ustawiana wysokosc
    void setHeight(int height);
    /// \brief getWidth
    /// \details Zwraca wysokość boiska
    int getWidth();
    /// \brief setWidth
    /// \details Ustawia szerokosc boiska
    /// \param width ustawiana szerokosc
    void setWidth(int width);
    /// \brief getActionInProgress
    /// \details Zwraca zmienną actionInProgress
    bool getActionInProgress();
    /// \brief setActionInProgress
    /// \details Ustawia parametr actionInProgress
    /// \param actionInProgress Ustawiana wartość zmiennej
    void setActionInProgress(bool actionInProgress);
    /// \brief getServed
    /// \details Zwraca zmienną served
    bool getServed();
    /// \brief setServed
    /// \details Ustawia parametr served
    /// \param served Ustawiana wartość zmiennej
    void setServed(bool served);
    /// \brief getOut
    /// \details Zwraca zmienną out
    bool getOut();
    /// \brief setOut
    /// \details Ustawia parametr out
    /// \param out Ustawiana wartość zmiennej
    void setOut(bool out);
    /// \brief getObjects
    /// \details Zwraca listę wszystkich obiektów na boisku
    QList <LogicObject *> &getObjects();
    /// \brief getTeam1
    /// \details Zwraca wskaznik do drużyny 1
    Team *getTeam1();
    /// \brief getTeam2
    /// \details Zwraca wskaznik do drużyny 2
    Team *getTeam2();
};

#endif // COURT_H
