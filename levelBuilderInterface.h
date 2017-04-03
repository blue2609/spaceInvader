#ifndef levelBuilderInterface_H
#define levelBuilderInterface_H
#include "gamelevel.h"

class levelBuilderInterface{
public:

    //specify a constructor that can be used by derived classes
    //to inialize the inherited data members
    levelBuilderInterface(int noOfWaves,
                          int noOfLevel,
                          float levelEnemyDamage,
                          float levelEnemyShootingSpeed):

        m_noOfWaves(noOfWaves),
        m_noOfLevel(noOfLevel),
        m_levelEnemyDamage(levelEnemyDamage),
        m_levelEnemyShootingSpeed(levelEnemyShootingSpeed){}

    virtual void buildWaveOfEnemies() = 0;
    virtual void assignLevelNumber() = 0;
    virtual void assignEnemyDamage() = 0;
    virtual void assignEnemyShootingSpeed() = 0;
    virtual gameLevel getLevel() = 0;
    virtual ~levelBuilderInterface(){}

protected:
    int m_noOfWaves;
    int m_noOfLevel;
    float m_levelEnemyDamage;
    float m_levelEnemyShootingSpeed;
};

#endif // levelBuilderInterface_H
