#ifndef LOGICOBJECT_H
#define LOGICOBJECT_H
#include <QtGlobal>
#include <QString>

class Court;
class Player;

class LogicObject {
private:
    /// \brief x
    /// \details Współrzędna x obiektu
    int x;
    /// \brief y
    /// \details Współrzędna y obiektu
    int y;
    /// \brief height
    /// \details Wysokość obiektu
    int height;
    /// \brief width
    /// \details Szerokość obiektu
    int width;
    /// \brief startX
    /// \details Początkowa współrzędna x obiektu
    int startX;
    /// \brief startY
    /// \details Początkowa współrzędna y obiektu
    int startY;
    /// \brief direction
    /// \details Kierunek ruchu obiektu
    int direction;
    /// \brief targetX
    /// \details Docelowa współrzędna x obiektu
    int targetX;
    /// \brief targetY
    /// \details Docelowa współrzędna y obiektu
    int targetY;
    /// \brief parent
    /// \details Ostatni obiekt z którym ten obiekt kolidował
    LogicObject *parent;
    /// \brief court
    /// \details Wskaźnik na boisko
    Court *court;
public:
    LogicObject(int startX, int startY, int height, int width, Court *court);
    /// \brief getX
    /// \details Zwraca współrzędną x
    int getX();
    /// \brief getStartX
    /// \details Zwraca początkową współrzędną x
    int getStartX();
    /// \brief getY
    /// \details Zwraca współrzędną y
    int getY();
    /// \brief getStartY
    /// \details Zwraca początkową współrzędną y
    int getStartY();
    /// \brief getHeight
    /// \details Zwraca wysokość obiektu
    int getHeight();
    /// \brief getWidth
    /// \details Zwraca szerokość obiektu
    int getWidth();
    /// \brief getDirection
    /// \details Zwraca kierunek ruchu obiektu
    int getDirection();
    /// \brief getTargetX
    /// \details Zwraca docelową współrzędną x
    int getTargetX();
    /// \brief getTargetY
    /// \details Zwraca docelową współrzędną y
    int getTargetY();
    /// \brief getParent
    /// \details Zwraca wskaźnik na ostatni kolidujący obiekt
    LogicObject *getParent();
    /// \brief getCourt
    /// \details Zwraca wskaźnik na boisko
    Court *getCourt();

    /// \brief setX
    /// \details Ustawia współrzędną x
    /// \param served Ustawiana wartość zmiennej
    void setX(int x);
    /// \brief setY
    /// \details Ustawia współrzędną y
    /// \param served Ustawiana wartość zmiennej
    void setY(int y);
    /// \brief setHeight
    /// \details Ustawia wysokość obiektu
    /// \param served Ustawiana wartość zmiennej
    void setHeight(int height);
    /// \brief setWidth
    /// \details Ustawia szerokość obiektu
    /// \param served Ustawiana wartość zmiennej
    void setWidth(int width);
    /// \brief setDirection
    /// \details Ustawia kierunek ruchu obiektu
    /// \param served Ustawiana wartość zmiennej
    void setDirection(int direction);
    /// \brief setTargetX
    /// \details Ustawia docelową współrzędną x
    /// \param served Ustawiana wartość zmiennej
    void setTargetX(int x);
    /// \brief setTargetY
    /// \details Ustawia docelową współrzędną y
    /// \param served Ustawiana wartość zmiennej
    void setTargetY(int y);
    /// \brief setParent
    /// \details Ustawia ostatni obiekt kolidujący z danym obiektem
    /// \param served Ustawiana wartość zmiennej
    void setParent(LogicObject *parent);

    /// \brief update
    /// \details Wirtualna funkcja realizowana przez klasy dziedziczące
    virtual void update() = 0;
    /// \brief getLogicObject
    /// \details Zwraca wskaźnik na dany obiekt
    LogicObject *getLogicObject();
};

#endif // LOGICOBJECT_H
