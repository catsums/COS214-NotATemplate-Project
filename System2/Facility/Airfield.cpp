#include <iostream>
#include "Airfield.h"

using namespace std;

Airfield::Airfield(int r, int h) : Facility(){
    runways = r;
    hangers = h;
    types.push_back("Airfield");
}
Airfield::Airfield(int r, int h, string c) : Facility(c){
    runways = r;
    hangers = h;
    types.push_back("Airfield");
}

void Airfield::displayFacility()
{
    cout << "Airfield with " << hangers << " Hangers and " << runways << " Runways" << endl;
}