#include "spaceship.h"

//set up the starting coordinate of the ship
//as well as its movement speed (and direction)
spaceShip::spaceShip(int initialxCoordinate,
                     int initialyCoordinate,
                     int movementSpeed,
                     int maxX,
                     int shipWidth,
                     int shipHeight):
    m_initialxCoordinate(initialxCoordinate),
    m_initialyCoordinate(initialyCoordinate),
    m_movementSpeed(movementSpeed),
    m_maxX(maxX){
    m_spaceShipImage.load(":/images/defender.png");
    m_spaceShipImage = m_spaceShipImage.scaled(shipWidth,shipHeight);
}

void spaceShip::nextFrame(){
    //animate the space ship
    m_initialxCoordinate += m_movementSpeed;

    if(m_initialxCoordinate >= m_maxX){
        m_initialxCoordinate = (2*m_maxX) - m_initialxCoordinate;
        m_movementSpeed *= -1;
    }else if (m_initialxCoordinate <= 0){
        m_initialxCoordinate *= -1;
        m_movementSpeed *= -1;
   }
}

void spaceShip::setMovementDirection(int direction){
    m_movementSpeed = m_movementSpeed * direction;
}

//getter for the new x Coordinate so it can be accessed
//by the weapon object in nextFrame() method
int spaceShip::getNewxCoordinate(){
    return m_initialxCoordinate;
}

//getter for the new y Coordinate so it can be accessed
//by the weapon object in nextFrame() method
int spaceShip::getNewyCoordinate(){
    return m_initialyCoordinate;
}

int spaceShip::getMovementSpeed(){
    return m_movementSpeed;
}

//getter for the space ship QPixmap object so it can be accessed
//by the weapon object in the nextFrame() method
QPixmap spaceShip::getSpaceShipImage(){
    return m_spaceShipImage;
}

int spaceShip::getMaxX(){
    return m_maxX;
}

