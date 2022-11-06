#include <iostream>
#include "FOBDispenser.h"

FOBDispenser::FOBDispenser(int t) : Dispenser(), territory(t) {}; 
        
void FOBDispenser::dispense(int ft) {
    while(ft >= territory) {
        //cout << "R" << territory << " dispenser dispenses R" << territory << endl; 
        ft -= territory;
    }
    //cout << "R" << ft << " to small for R" << territory << " dispenser - passed on" << endl; 
    Dispenser::dispense(ft);
}