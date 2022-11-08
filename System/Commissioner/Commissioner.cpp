#include <iostream>
#include "Commissioner.h"

Commissioner::Commissioner() : next(0) {}

void Commissioner::add(Commissioner *n) {
    if (next) 
        next->add(n);
    else
        next = n;
}

void Commissioner::commission(int i, bool c) {
    if(i > 0) { 
        if (next)
            next->commission(i, c); 
        else {
            leftOver += i;
        }
    } else
    {
        //cout << "Required amount was dispensed" << endl;
    }
         
}

void Commissioner::getInfo(vector<FOB*> f, Commissioner* c) {
    if (next) {
        for(FOB* i : facilities) 
            f.push_back(i);
        next->getInfo(f, c);
    } else {
        c->leftOver = leftOver;
        c->facilities = f;
    }
}

int Commissioner::getLeftOver() {
    return leftOver;
}

void Commissioner::setFacilities(FOB* fob) {
    facilities.push_back(fob);
}

vector<FOB*> Commissioner::getFacilities() {
    return facilities;
}