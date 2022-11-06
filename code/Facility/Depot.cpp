#include <iostream>
#include "Depot.h"

using namespace std;

Depot::Depot(int g) : garages(g){}

void Depot::Depot()
{
    cout << "Army depot with " << garages << " garages" << endl;
}