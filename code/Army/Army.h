#ifndef ARMY_H
#define ARMY_H

#include <iostream>
#include <string>
#include <vector>

#include "ArmyForce.h"

using namespace std;

class Army{
private:
    ArmyForce* m_attack;
public:
    Army();
    ~Army();
    void set_attack(ArmyForce* a);
    bool attack();
};

#endif

