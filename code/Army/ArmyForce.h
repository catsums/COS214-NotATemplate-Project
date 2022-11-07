#ifndef ARMYFORCE_H
#define ARMYFORCE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Entity/Entity.h"
#include "../myHelper.cpp"

using namespace std;

class ArmyForce
{
protected:
    string strategy;
public:
    ArmyForce(string strat){
        strategy = strat;
    }
    ~ArmyForce(){
        
    }

    virtual vector<Entity*> getActiveForce(vector<Entity*> ents) = 0;

    string getStrategyName(){
        return strategy;
    }

};

#endif

