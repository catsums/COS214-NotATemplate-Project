#include <iostream>
#include "Fortification.h"

using namespace std;

Fortification::Fortification(int l):Facility(){
    types.push_back("Fortification");
}
Fortification::Fortification(int l, string c):Facility(c){
    types.push_back("Fortification");
}

void Fortification::displayFacility()
{
    cout << "Fortification with defense level " << defenseLevel << endl;
}