#include "Country.h"

Country::Country(string n, bool s, bool c) : name(n), side(s), coastal(c)
{
    //generate random territory
    //srand(time(0));
    territory = rand() % 40 + 10;
    freeSpace = 0;

    //assign recources
    resources = territory * (rand() % 5 + 1);

    cArmy = new Army(resources);
    resources = 0;
}

int Country::generateResources()
{
    resources += territory * (8 + rand() % 5);
    //check for resource gen buildings

    return resources;
}

void Country::recruit()
{
    cArmy->recruit(resources);
    resources = 0;
}

bool Country::getSide(){
    return side;
}

void Country::setSide(bool s){
    side = s;
}

bool Country::getCoastal(){
    return coastal;
}

string Country::getName(){
    return name;
}

void Country::updateResources(int u)
{
    resources += u;
}

void Country::updateTerritory(int t, int fs)
{
    territory += t;
    freeSpace += fs;
}

void Country::addBases(vector<FOB*> nb)
{
    for(int i = 0; i < nb.size(); i++)
    {
        bases.push_back(nb[i]);
    }
}

void Country::checkBaseCapacity()
{
    while(baseSpace() > territory)
    {
        int b2d = (rand() % bases.size());

        if(bases[b2d]->getSpace() > 0)
        {
            bases[b2d]->removeFacility();
            if(bases[b2d]->getSpace() == 0)
            {
                freeSpace += bases[b2d]->getSpace();
                bases.erase(bases.begin() + b2d);
            }
        }
        
    }
}

int Country::baseSpace()
{
    int n = 0;
    for(int i = 0; i < bases.size(); i++)
    {
        n += bases[i]->getSpace();
    }
    return n;
}

int Country::getResources(){
    return resources;
}

int Country::getTerritory(){
    return territory;
}

int Country::getFreeSpace(){
    return freeSpace;
}

Army* Country::getArmy(){
    return cArmy;
}