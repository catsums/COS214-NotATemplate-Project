#include "Country.h"

Country::Country(string n, bool s) : name(n), side(s)
{
    //generate random territory
    //srand(time(0));
    territory = rand() % 40 + 10;

    //assign recources
    resources = territory * (rand() % 5 + 1);
}

int Country::generateResources()
{
    resources += territory * (8 + rand() % 5);
    //check for resource gen buildings

    return resources;
}

bool Country::getSide(){
    return side;
}

void Country::setSide(bool s){
    side = s;
}

string Country::getName(){
    return name;
}

void Country::updateResources(int u)
{
    resources += u;
}

void Country::updateTerritory(int u)
{
    territory += u;
}

int Country::getResources(){
    return resources;
}

int Country::getTerritory(){
    return territory;
}