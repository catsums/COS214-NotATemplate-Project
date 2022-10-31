#include <iostream>
#include "Airfield.h"

using namespace std;

Airfield::Airfield(int r, int h) : runways(r), hangers(h){}

void Airfield::displayFacility()
{
    cout << "Airfield with " << hangers << " Hangers and " << runways << " Runways" << endl;
}