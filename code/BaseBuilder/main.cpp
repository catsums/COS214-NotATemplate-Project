#include <iostream>

#include "BaseBuilder.h"

using namespace std;

int main() {
    srand(time(0));
    BaseBuilder bb(1, true);
    FOB* fobbyb = bb.getResult();
    fobbyb->displayFacility();
    
}