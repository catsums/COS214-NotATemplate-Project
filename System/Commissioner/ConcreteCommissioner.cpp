#include <iostream>
#include "FOBCommissioner.h"

FOBCommissioner::FOBCommissioner(int t) : Commissioner(), territory(t) {}; 
        
void FOBCommissioner::commission(int ft, bool coastal) {
    while(ft >= territory) {
        //pass territory/5 to builder
        //cout << "R" << territory << " Commissioner dispenses R" << territory << endl; 
        
        ft -= territory;
    }
    //cout << "R" << ft << " to small for R" << territory << " Commissioner - passed on" << endl; 
    Commissioner::commission(ft, bool coastal);
}