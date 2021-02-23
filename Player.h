#ifndef PLAYER_H
#define PLAYER_H
#include "LogicObject.h"

class Team;

class Player: public LogicObject {
private:
    /// \brief team
    /// \details Wskaźnik na zespół do którego należy zawodnik
    Team *team;
public:
    Player(int x, int y, int height, int width, Court *court, Team *team);
    /// \brief getTeam
    /// \details Zwraca wskaźnik do zespołu
    Team *getTeam();
    /// \brief move
    /// \details Funkcja odpowiadająca za zmianę  współrzędnych zawodników do symulowania ruchu
    void move();
    /// \brief update
    /// \details Wirtualna funkcja realizowana przez klasy dziedziczące
    virtual void update() = 0;
};

#endif // PLAYER_H
