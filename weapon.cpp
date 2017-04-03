#include "weapon.h"

//give the weapon initial coordinates and travel speed (and direction)
weapon::weapon(int initialxCoordinate,
               int initialyCoordinate,
               int movementSpeed,
               int spaceShipxCoordinate,
               int spaceShipyCoordinate,
               QPixmap spaceShipImage):
    m_initialxCoordinate(initialxCoordinate),
    m_initialyCoordinate(initialyCoordinate),
    m_movementSpeed(movementSpeed),
    m_spaceShipInitialxCoordinate(spaceShipxCoordinate),
    m_spaceShipInitialyCoordinate(spaceShipyCoordinate),
    m_spaceShipImage(spaceShipImage){
    m_weaponImage.load(":/images/fireball.png");
}

//GETTERS
int weapon::getNewxCoordinate(){
    return m_initialxCoordinate;
}

int weapon::getNewyCoordinate(){
    return m_initialyCoordinate;
}

QPixmap weapon::getWeaponImage(){
    return m_weaponImage;
}

void weapon::nextFrame(){
    //give the weapon new location for the next frame
    if(m_initialyCoordinate <= -100){
        m_initialxCoordinate = m_spaceShipInitialxCoordinate +
                (m_spaceShipImage.width()/2) - (m_weaponImage.width()/2);
        m_initialyCoordinate= m_spaceShipInitialyCoordinate -
                m_weaponImage.height();
    }else{
        m_initialyCoordinate -= m_movementSpeed;
    }
}





