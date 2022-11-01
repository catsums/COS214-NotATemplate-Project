#include <vector>
#include <iostream>
#include "FOB.h"

using namespace std;

FOB::FOB():Facility(){

}

void FOB::displayFacility()
{
    cout << "Forward Operating Base comprising of: " << endl;
    for(auto fac : facilities)
    {
        fac->displayFacility();
    }
}

bool Zone::addFacility(Facility* fac){
    if(!hasFacility(fac)){
        if((fac->isOnLand() == this->isOnLand()) && (fac->isOnSea() == this->isOnSea())){
            facilities.push_back(fac);
            return true;
        }
    }
    return false;
}
Facility* Zone::removeFacility(Facility* fac){
    Facility* _fac = NULL;
    for(int i=0;i<(int)facilities.size();i++){
        Facility* f = facilities[i];
        if(f==fac || f->getID() == fac){
            _fac = f;
            facilities.erase(i);
            break;
        }
    }
    return _fac;
}

bool Zone::hasFacility(Facility* fac){
    if(!fac) return false;
    for(int i=0;i<(int)facilities.size();i++){
        Facility* f = facilities[i];
        if(f==fac || f->getID() == fac){
            return true;
        }
    }

    return false;
}