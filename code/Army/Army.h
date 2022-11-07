#ifndef ARMY_H
#define ARMY_H


#include "ArmyForce.h"


class Army
{
private:
    ArmyForce *m_attack;
public:
    Army();
    void set_attack(ArmyForce* a);
    bool const attack(Army* other);
};

#endif

