#ifndef GAMELEVEL_H
#define GAMELEVEL_H
#include "levelinterface.h"


//THIS IS THE CONCRETE CLASS which will implement
//"levelInterface" interface

class gameLevel : public levelInterface
{
public:
    //the constructor
    gameLevel();

    //declare all of the pure virtual methods from levelInterface
    void setWaveOfEnemies(int waveOfEnemies);
    void setLevelNumber(int levelNumber);
    void setEnemyDamage(float enemyDamage);
    void setEnemyShootingSpeed(float enemyShootingSpeed);

    //destructor for gameLevel class
    virtual ~gameLevel(){}


};

#endif // GAMELEVEL_H
