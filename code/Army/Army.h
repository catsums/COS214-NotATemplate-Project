#ifndef ARMY_H
#define ARMY_H


#include "ArmyForce.h"


class Army
{
private:
    ArmyForce *m_attack;
public:
    Army();
    bool attack();
};

#endif

