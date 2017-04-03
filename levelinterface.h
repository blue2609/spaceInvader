#ifndef LEVELINTERFACE_H
#define LEVELINTERFACE_H

class levelInterface{
public:
    virtual void setWaveOfEnemies(int waveOfEnemies) = 0;
    virtual void setLevelNumber(int levelNumber) = 0;
    virtual void setEnemyDamage(float enemyDamage) = 0;
    virtual void setEnemyShootingSpeed(float enemyShootingSpeed) = 0;
    virtual ~levelInterface(){}
protected:
    int m_waveOfEnemies;
    int m_levelNumber;
    float m_enemyDamage;
    float m_enemyShootingSpeed;
};

#endif // LEVELINTERFACE_H
