#ifndef GROUNDFORCE_H
#define GROUNDFORCE_H

#include "ArmyForce.h"

class GroundForce : public ArmyForce
{
private:
    /* data */

public:
    ~GroundForce(){};
    virtual bool attack();
};

#endif
