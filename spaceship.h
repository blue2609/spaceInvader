#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QPixmap>


class spaceShip
{
public:
    spaceShip(int initialxCoordinate,
              int initialyCoordinate,
              int movementSpeed,
              int maxX,
              int shipWidth,
              int shipHeight);
    spaceShip(){}
    void nextFrame();
    int getNewxCoordinate();
    int getNewyCoordinate();
    int getMovementSpeed();
    int getMaxX();
    void setMovementDirection(int direction);
    QPixmap getSpaceShipImage();
protected:
    //starting coordinate of the ship at each frame
    int m_initialxCoordinate;
    int m_initialyCoordinate;

    //the maximum x space the space ship can move
    int m_maxX;

    //movement speed of the space ship
    int m_movementSpeed;

    //give the class a spaceship image representation
    QPixmap m_spaceShipImage;
};

#endif // SPACESHIP_H
