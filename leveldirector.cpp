#include "leveldirector.h"

//assign the levelBuilder object to the member variable
//m_levelBuilder
levelDirector::levelDirector(normalLevelBuilder levelBuilder):
    m_levelBuilder(levelBuilder){

    //construct the game level using the builder
    m_levelBuilder.buildWaveOfEnemies();
    m_levelBuilder.assignLevelNumber();
    m_levelBuilder.assignEnemyDamage();
    m_levelBuilder.assignEnemyShootingSpeed();

}


//return the level made by this level director
gameLevel levelDirector::getLevel(){
    return m_levelBuilder.getLevel();
}



