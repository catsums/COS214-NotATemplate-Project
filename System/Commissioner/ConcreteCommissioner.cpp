#include <iostream>
#include "ConcreteCommissioner.h"
#include "../BaseBuilder/BaseBuilder.h"

ConcreteCommissioner::ConcreteCommissioner(int t) : Commissioner(), territory(t) {}; 
        
void ConcreteCommissioner::commission(int ft, bool coastal) {
    while(ft >= territory) {
        BaseBuilder bb(territory/5, coastal);
        FOB* fobbyb = bb.getResult();
        setFacilities(fobbyb);
        fobbyb->displayFacility();
        cout << endl;
        ft -= territory;
    }
    //cout << "R" << ft << " to small for R" << territory << " Commissioner - passed on" << endl; 
    Commissioner::commission(ft, coastal);
}