#include <iostream>
#include "Depot.h"

using namespace std;

Depot::Depot(int g) : garages(g){}
Depot::~Depot(){}

void Depot::displayFacility()
{
    cout << "Army depot with " << garages << " garages" << endl;
}

int Depot::getGarages()
{
    return garages;
}