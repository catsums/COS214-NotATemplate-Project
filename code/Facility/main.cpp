#include <iostream>

#include "Facility.h"
#include "FOB.cpp"
#include "Airfield.cpp"
#include "Hospital.cpp"
#include "Fortification.cpp"

using namespace std;

int main()
{
    FOB* f1 = new FOB();
    FOB* f2 = new FOB();

    f1->addFacility(new Airfield(2, 6));
    f1->addFacility(new Hospital(4000, 2));
    f1->addFacility(new Hospital(200, 3));
    f1->addFacility(new Fortification(3));

    f2->addFacility(new Airfield(4, 10));
    f2->addFacility(f1);
    f2->addFacility(new Fortification(1));

    f1->displayFacility();
    //f2->displayFacility();
    
    delete f1;
    delete f2;

    return 0;
}