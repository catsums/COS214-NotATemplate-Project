#ifndef ARMY_CPP
#define ARMY_CPP

#include <iostream>

#include "Army.h"

using namespace std;

Army::Army(){
    force = NULL;
}
Army::~Army(){
    force = NULL;
}
bool Army::attack(Army* enemyArmy){
    force->attack(enemyArmy->force);
    return false;
}
void Army::set_attack(ArmyForce* a){
    force = a;
}


#endif