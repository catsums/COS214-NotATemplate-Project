#ifndef AIRFORCE_H
#define AIRFORCE_H

#include "ArmyForce.h"

class AirForce:public ArmyForce
{
private:
    /* data */
public:
    AirForce():ArmyForce(){

    }
    AirForce(vector<Entity*> army):ArmyForce(army){

    }
    ~AirForce(){

    }
};

#endif

