#include <iostream>
#include "Commissioner.h"

Commissioner::Commissioner() : next(0) {}

void Commissioner::add(Commissioner *n) {
    if (next) 
        next->add(n);
    else
        next = n;
}

virtual void Commissioner::commission(int i) {
    if(i > 0) { 
        if (next)
            next->commission(i); 
        else
            leftOver += i;
    } else
        //cout << "Required amount was dispensed" << endl; 
}

int Commissioner::getLeftOver() {
    return leftOver;
}

vector<FOB*> Commissioner::getFacilities() {
    return facilities;
}