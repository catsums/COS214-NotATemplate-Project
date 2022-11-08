#include "Battle.h"

#include <iostream>

Battle::Battle(Country* country1, Country* country2, int t) : c1(country1), c2(country2), theatre(t) {}

void Battle::commence() {
    cout << c1->getName() << " launched an attack against " << c2->getName() << " (Strategy)" << endl;
    determineOutcome();
}

//temporary implimentation
void Battle::determineOutcome()
{
    int victoryChance = ((double) c1->getTerritory() / (c1->getTerritory() + c2->getTerritory())) * 100;
    
    if((rand() % 100 + 1) <= victoryChance)
    {
        int t = (rand() % 20 + 1);
        cout << c1->getName() << " has defeated " << c2->getName() << " in battle | " << c1->getName() << " has captured " << t << " territory" << endl;
        
        c1->updateTerritory(t, t);
        c2->updateTerritory(-t, -t);

        c1->getArmy()->sufferCasualties(0.6);
        c2->getArmy()->sufferCasualties(0.8);
    }
    else
    {
        cout << c2->getName() << " has defeated " << c1->getName() << " in battle | " << c2->getName() << " has defended their territory" << endl;
        c1->getArmy()->sufferCasualties(0.8);
        c2->getArmy()->sufferCasualties(0.4);
    }
}
