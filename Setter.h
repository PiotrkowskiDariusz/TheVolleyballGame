#ifndef SETTER_H
#define SETTER_H
#include "Player.h"

class Setter: public Player {

public:
    Setter(int x, int y, int height, int width, Court *court, Team *team):Player(x, y, height, width, court, team){};
    /// \brief set
    /// \details Funkcja symulująca rozegranie piłki przez zawodnika
    void set();
    /// \brief update
    /// \details Funkcja wykrywająca kolizję z piłką i wywołująca odpowiednie działania w przypadku kolizji
    virtual void update();
};

#endif // SETTER_H
