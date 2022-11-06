#include <iostream>
#include "Port.h"

using namespace std;

Port::Port(int d) : docks(d){}

void Port::displayFacility()
{
    cout << "Port with " << docks << " docks" << endl;
}

int Port::getDocks()
{
    return docks;
}