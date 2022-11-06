#include "Country.h"

Country::Country(string n, bool s) : name(n), side(s)
{
    //generate random territory
    srand(time(0));
    territory = rand() % 40 + 10;

    //assign recources
    resources = territory * 5;
}

int Country::generateResources()
{
    resources += territory * 10;
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

int Country::getTerritory(){
    return territory;
}