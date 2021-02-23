#ifndef RECEIVER_H
#define RECEIVER_H
#include "Player.h"

class Receiver: public Player {

public:
    Receiver(int x, int y, int height, int width, Court *court, Team *team):Player(x, y, height, width, court, team){};
    /// \brief receive
    /// \details Funkcja symulująca przyjęcie piłki przez zawodnika
    void receive();
    /// \brief serve
    /// \details Funkcja symulująca serwowanie piłki przez zawodnika
    void serve();
    /// \brief update
    /// \details Funkcja wykrywająca kolizję z piłką i wywołująca odpowiednie działania w przypadku kolizji
    virtual void update();
};

#endif // RECEIVER_H
