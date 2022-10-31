#include <iostream>
#include "Fortification.h"

using namespace std;

Fortification::Fortification(int l) : defenseLevel(l){}

void Fortification::displayFacility()
{
    cout << "Fortification with defense level " << defenseLevel << endl;
}