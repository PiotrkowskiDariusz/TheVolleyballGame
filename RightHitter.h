#ifndef RIGHTHITTER_H
#define RIGHTHITTER_H
#include "Player.h"

class RightHitter: public Player {

public:
    RightHitter(int x, int y, int height, int width, Court *court, Team *team):Player(x, y, height, width, court, team){};
    /// \brief attack
    /// \details Funkcja symulująca atak zawodnika
    void attack();
    /// \brief update
    /// \details Funkcja wykrywająca kolizję z piłką i wywołująca odpowiednie działania w przypadku kolizji
    virtual void update();
};
#endif // RIGHTHITTER_H
