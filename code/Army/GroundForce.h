#ifndef GROUNDFORCE_H
#define GROUNDFORCE_H

#include "ArmyForce.h"

class GroundForce : public ArmyForce
{
private:
    /* data */

public:
    GroundForce():ArmyForce(){

    }
    GroundForce(vector<Entity*> army):ArmyForce(army){

    }
    ~GroundForce(){

    }
};

#endif
