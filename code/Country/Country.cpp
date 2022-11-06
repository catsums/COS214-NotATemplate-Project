#include "Country.h"

Country::Country(string n, bool s, bool c) : name(n), side(s), coastal(c)
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

bool Country::getCoastal(){
    return coastal;
}

string Country::getName(){
    return name;
}

int Country::getResources(){
    return resources;
}

int Country::getTerritory(){
    return territory;
}