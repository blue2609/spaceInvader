#ifndef LEVELDIRECTOR_H
#define LEVELDIRECTOR_H
#include "normallevelbuilder.h"


class levelDirector
{
public:
    levelDirector(normalLevelBuilder levelBuilder);
    gameLevel getLevel();
    virtual ~levelDirector(){}

protected:
    normalLevelBuilder m_levelBuilder;
};

#endif // LEVELDIRECTOR_H
