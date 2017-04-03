#include "gamelevel.h"

    gameLevel::gameLevel(){}

    //IMPLEMENTATION OF SETTERS BELOW

    //set the number of waves of enemies player has to fight
    //at this level
    void gameLevel::setWaveOfEnemies(int waveOfEnemies){
        m_waveOfEnemies = waveOfEnemies;
    }

    //set the level number player is currently in
    void gameLevel::setLevelNumber(int levelNumber){
        m_levelNumber = levelNumber;
    }

    //set the enemy damage enemy can inflict on player with each shot
    //or attack
    void gameLevel::setEnemyDamage(float enemyDamage){
        m_enemyDamage = enemyDamage;
    }

    //set the enemy weapon travel speed in the current level
    void gameLevel::setEnemyShootingSpeed(float enemyShootingSpeed){
        m_enemyShootingSpeed = enemyShootingSpeed;
    }

