#include <iostream>
#include <vector>

#include "Commissioner.h"
#include "ConcreteCommissioner.h"
#include "../Facility/FOB.h"

using namespace std;

int main() {
    srand(time(0));
    Commissioner* machine = new ConcreteCommissioner (20);
    machine->add(new ConcreteCommissioner (15)); 
    machine->add(new ConcreteCommissioner (10)); 
    machine->add(new ConcreteCommissioner (5)); 
    int t;
    bool bc;
    string sc;
    cout << "Amount of territory available:"; 
    cin >> t;
    cout << "Is country coastal (0/1):"; 
    cin >> sc;
    bc = stoi(sc);
    cout << endl;
    machine->commission(t, bc);
    cout << endl;
    vector<FOB*> facilities;
    machine->getInfo(facilities,machine);
    cout << endl;
    cout << machine->getLeftOver() << " territory left over" << endl;
    facilities = machine->getFacilities();
    for(FOB* i : facilities)
        i->displayFacility();
    
    return 0;
}