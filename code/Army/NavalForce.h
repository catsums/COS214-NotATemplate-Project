#ifndef NAVALFORCE_H
#define NAVALFORCE_H

#include "ArmyForce.h"

class NavalForce : public ArmyForce
{
private:
    /* data */
public:
    NavalForce():ArmyForce(){

    }
    NavalForce(vector<Entity*> army):ArmyForce(army){

    }
    ~NavalForce(){

    }
};

#endif
