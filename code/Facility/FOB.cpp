#include <vector>
#include <iostream>
#include "FOB.h"

using namespace std;

FOB::FOB(){}

void FOB::displayFacility()
{
    cout << "Forward Operating Base comprising of: " << endl;
    for(auto fac : facilities)
    {
        fac->displayFacility();
    }
}

void FOB::addFacility(Facility* f)
{
    facilities.push_back(f);
}