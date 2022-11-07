#include <iostream>
#include "Airfield.h"

using namespace std;

Airfield::Airfield(int h) : hangers(h){}

void Airfield::displayFacility()
{
    cout << "Airfield with " << hangers << " Hangers" << endl;
}

int Airfield::getHangers()
{
    return hangers;
}