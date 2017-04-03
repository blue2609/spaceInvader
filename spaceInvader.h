#ifndef spaceInvader_H
#define spaceInvader_H

#include "spaceship.h"
#include "weapon.h"
#include <QDialog>
#include <QPainter>
#include <QPixmap>




class spaceInvader : public QDialog
{
    Q_OBJECT
public:
    explicit spaceInvader(QWidget *parent = 0);
    ~spaceInvader();

protected:
    void paintEvent(QPaintEvent *event);
    spaceShip m_ship;
    weapon m_weapon;
public slots:
    void nextFrame();
};


#endif // spaceInvader_H
