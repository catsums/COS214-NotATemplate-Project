#ifndef ARMY_CPP
#define ARMY_CPP

#include <iostream>

#include "Army.h"

using namespace std;

Army::Army(){
    m_attack = NULL;
    // cout <<"Army created"<<endl;
}
Army::~Army(){
    m_attack = NULL;
}
bool Army::attack(){
    m_attack->attack();
    return false;
}
void Army::set_attack(ArmyForce* a){
    m_attack = a;
}


#endif