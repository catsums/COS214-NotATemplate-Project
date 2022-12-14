#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <time.h> 
#include "FOB.h"

using namespace std;

FOB::FOB(){}

void FOB::displayFacility()
{
    cout << "Forward Operating Base comprising of: " << endl;
    for(auto i : facilities)
    {
        i->displayFacility();
    }
}

void FOB::addFacility(Facility* f)
{
    facilities.push_back(f);
}

void FOB::removeFacility()
{
   if (facilities.size() > 0)
   {
        srand (time(NULL));
        int position = rand() % facilities.size() + 0;
        facilities.erase(facilities.begin()+position);
   }
}

vector<Facility*> FOB::getFacilities()
{
    return facilities;
}

int FOB::getSpace()
{
    int n = 0;
    for(auto i : facilities)
    {
        n += 5;
    }
    return n;
}