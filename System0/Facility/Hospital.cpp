#include <iostream>
#include "Hospital.h"

using namespace std;

Hospital::Hospital(int c) : capacity(c){}
Hospital::~Hospital(){}

void Hospital::displayFacility()
{
    cout << "Hospital with capacity of " << capacity << endl;
}

int Hospital::getCapacity()
{
    return capacity;
}