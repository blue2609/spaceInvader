#ifndef WEAPON_H
#define WEAPON_H
#include <QPixmap>

class weapon
{
public:
    weapon(){}
    weapon(int initialxCoordinate,
           int initialyCoordinate,
           int movementSpeed,
           int spaceShipxCoordinate,
           int spaceShipyCoordinate,
           QPixmap spaceShipImage);
    void nextFrame();
    int getNewxCoordinate();
    int getNewyCoordinate();
    QPixmap getWeaponImage();
protected:
    //starting coordinate of the weapon at each frame
    int m_initialxCoordinate;
    int m_initialyCoordinate;

    //movement speed of the bullet
    int m_movementSpeed;

    //initial x coordinate of the spaceship
    int m_spaceShipInitialxCoordinate;
    int m_spaceShipInitialyCoordinate;

    //give the class a weapon image representation in the form
    //of a bullet/fireball/laser
    QPixmap m_weaponImage;
    QPixmap m_spaceShipImage;
};

#endif // WEAPON_H
