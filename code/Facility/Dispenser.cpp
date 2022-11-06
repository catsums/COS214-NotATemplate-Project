#include <iostream>
#include "Dispenser.h"

Dispenser::Dispenser() : next(0) {}

void Dispenser::add(Dispenser *n) {
    if (next) 
        next->add(n);
    else
        next = n;
}

virtual void Dispenser::dispense(int i) {
    if(i > 0) { 
        if (next)
            next->dispense(i); 
        else
            leftOver += i;
    } else
        //cout << "Required amount was dispensed" << endl ; 
}

int Dispenser::getleftOver() {
    return leftOver;
}