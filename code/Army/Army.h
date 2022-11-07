#ifndef ARMY_H
#define ARMY_H

#include <iostream>
#include <string>
#include <vector>

#include "ArmyForce.h"

using namespace std;

class Army{
protected:
    ArmyForce* force;
public:
    Army();
    ~Army();
    void set_attack(ArmyForce* a);
    bool attack(Army* enemyArmy);
};

#endif

