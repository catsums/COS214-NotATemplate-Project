#include <iostream>
#include "Port.h"

using namespace std;

Port::Port(int d) : docks(d){}

void Depot::Depot()
{
    cout << "Port with " << docks << " docks" << endl;
}