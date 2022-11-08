#include <iostream>

#include "BaseBuilder.h"

using namespace std;

int main() {
    srand(time(0));

    BaseBuilder bb1(1, true);
    BaseBuilder bb2(2, true);
    BaseBuilder bb3(3, true);
    BaseBuilder bb4(4, true);
    BaseBuilder bb5(2, false);

    FOB* fobbyb = bb1.getResult();
    fobbyb->displayFacility();
    
    fobbyb = bb2.getResult();
    fobbyb->displayFacility();

    fobbyb = bb3.getResult();
    fobbyb->displayFacility();

    fobbyb = bb4.getResult();
    fobbyb->displayFacility();

    fobbyb = bb5.getResult();
    fobbyb->displayFacility();
}