#ifndef NORMALLEVELBUILDER_H
#define NORMALLEVELBUILDER_H
#include "levelBuilderInterface.h"


class normalLevelBuilder : public levelBuilderInterface
{
public:
    normalLevelBuilder(int noOfWaves,
                       int noOfLevel,
                       float levelEnemyDamage,
                       float levelEnemyShootingSpeed);
    void buildWaveOfEnemies();
    void assignLevelNumber();
    void assignEnemyDamage();
    void assignEnemyShootingSpeed();
    gameLevel getLevel();
    virtual ~normalLevelBuilder(){}
protected:
    gameLevel normalLevel;

};

#endif // NORMALLEVELBUILDER_H
