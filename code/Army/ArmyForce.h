#ifndef ARMYFORCE_H
#define ARMYFORCE_H

#include "Army.h"

class ArmyForce
{
private:
    /* data */
public:
    ArmyForce(){};
    virtual bool attack(Army* other) = 0;
};

#endif

