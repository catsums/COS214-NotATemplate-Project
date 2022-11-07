#include "Army.h"

#include <iostream>

using namespace std;

Army::Army()
{
    cout <<"Army created"<<endl;
}
bool const Army::attack(Army* other)
{
    m_attack->attack(other);
    return false;
}
void Army::set_attack(ArmyForce* a)
{
    m_attack = a;
}


