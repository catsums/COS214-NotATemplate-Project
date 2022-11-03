#include "Battle.h"

#include <iostream>

Battle::Battle(Country* country1, Country* country2, int t) : c1(country1), c2(country2), theatre(t) {}

void Battle::commence() {
    cout << "Battle commenced " << c1->getName() << " VS " << c2->getName() << endl;
}
