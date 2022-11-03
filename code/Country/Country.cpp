#include "Country.h"

Country::Country(string n, bool s) : name(n), side(s)
{

}

bool Country::getSide(){
    return side;
}

string Country::getName(){
    return name;
}