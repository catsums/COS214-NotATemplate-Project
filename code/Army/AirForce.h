#ifndef AIRFORCE_H
#define AIRFORCE_H

#include "ArmyForce.h"

class AirForce:public ArmyForce
{
private:
    /* data */
public:
    AirForce(/* args */);
    ~AirForce();
    virtual bool attack();
};

#endif

