#ifndef NAVALFORCE_H
#define NAVALFORCE_H

#include "ArmyForce.h"

class NavalForce : public ArmyForce
{
private:
    /* data */
public:
    NavalForce(/*rgs */){};
    ~NavalForce(){};
    virtual bool attack(Army* other);
};

#endif
