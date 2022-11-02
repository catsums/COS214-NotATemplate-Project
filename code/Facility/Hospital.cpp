#include <iostream>
#include "Hospital.h"

using namespace std;

Hospital::Hospital(string c, int cap, int lvl) : Facility(){
    capacity = cap;
    techLevel = lvl;

    types.push_back("Hospital");
}
Hospital::Hospital(string c, int cap, int lvl) : Facility(c){
    capacity = cap;
    techLevel = lvl;

    types.push_back("Hospital");
}

void Hospital::displayFacility()
{
    cout << "Hospital with capacity of " << capacity << " and tech level " << techLevel << endl;
}