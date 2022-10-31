#include <iostream>
#include "Hospital.h"

using namespace std;

Hospital::Hospital(int c, int l) : capacity(c), techLevel(l){}

void Hospital::displayFacility()
{
    cout << "Hospital with capacity of " << capacity << " and tech level " << techLevel << endl;
}