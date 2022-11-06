#include "Battle.h"

#include <iostream>

Battle::Battle(Country* country1, Country* country2, int t) : c1(country1), c2(country2), theatre(t) {}

void Battle::commence() {
    cout << "Battle commenced " << c1->getName() << " VS " << c2->getName() << " | Theatre: " << theatre << endl;
    determineOutcome();
}

//temporary implimentation
void Battle::determineOutcome()
{
    if((rand() % 10 + 1) <= 6)
    {
        int t = (rand() % 10 + 1);
        cout << c1->getName() << " has defeated " << c2->getName() << " in battle | " << c2->getName() << " lost " << t << " territory" << endl;
        
        c1->updateTerritory(t);
        c2->updateTerritory(-t);
    }
    else
    {
        int t = (rand() % 10 + 1);
        cout << c2->getName() << " has defeated " << c1->getName() << " in battle | " << c1->getName() << " lost " << t << " territory" << endl;
        
        c2->updateTerritory(t);
        c1->updateTerritory(-t);
    }
}
