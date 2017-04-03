#include "normallevelbuilder.h"

//assign all the passed values to each data member in the builder
normalLevelBuilder::normalLevelBuilder(int noOfWaves,
                                       int noOfLevel,
                                       float levelEnemyDamage,
                                       float levelEnemyShootingSpeed):
    levelBuilderInterface(noOfWaves,
                          noOfLevel,
                          levelEnemyDamage,
                          levelEnemyShootingSpeed){}


//BUILD A NORMAL LEVEL OBJECT
void normalLevelBuilder::buildWaveOfEnemies(){
    normalLevel.setWaveOfEnemies(m_noOfWaves);
}

void normalLevelBuilder::assignLevelNumber(){
    normalLevel.setLevelNumber(m_noOfLevel);
}

void normalLevelBuilder::assignEnemyDamage(){
    normalLevel.setEnemyDamage(m_levelEnemyDamage);
}

void normalLevelBuilder::assignEnemyShootingSpeed(){
    normalLevel.setEnemyShootingSpeed(m_levelEnemyShootingSpeed);
}

//return a pointer to the normalLevel object
gameLevel normalLevelBuilder::getLevel(){
    return normalLevel;
}
