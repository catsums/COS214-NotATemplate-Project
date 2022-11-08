#include <iostream>
#include "ConcreteCommissioner.h"
#include "../BaseBuilder/BaseBuilder.h"

ConcreteCommissioner::ConcreteCommissioner(int t) : Commissioner(), territory(t) {}; 
ConcreteCommissioner::~ConcreteCommissioner(){}

void ConcreteCommissioner::commission(int ft, bool coastal) {
    while(ft >= territory) {
        BaseBuilder bb(territory/5, coastal);
        FOB* fobbyb = bb.getResult();
        setFacilities(fobbyb);
        ft -= territory;
    }
    Commissioner::commission(ft, coastal);
}