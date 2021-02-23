#ifndef TEAM_H
#define TEAM_H
#include <QString>
#include <QList>
#include "Player.h"

using namespace std;

class Team {
private:
    /// \brief name
    /// \details Nazwa drużyny
    QString name;
    /// \brief points
    /// \details Liczba punktów zdobytych przez drużynę
    int points;
    /// \brief players
    /// \details Wskaźnik na listę zawodników należących do danej drużyny
    QList <Player *> players;
public:
    Team(QString name);
    /// \brief getPlayers
    /// \details Zwraca listę zawodników należących do danej drużyny
    QList <Player *> &getPlayers();
    /// \brief getPoints
    /// \details Zwraca liczbę punktów zdobytych przez drużynę
    int getPoints();
    /// \brief setPoints
    /// \details Ustawia liczbę punktów zdobytych przez drużynę
    /// \param served Ustawiana wartość zmiennej
    void setPoints(int points);
    /// \brief getName
    /// \details Zwraca nazwę drużyny
    QString getName();

};

#endif // TEAM_H
