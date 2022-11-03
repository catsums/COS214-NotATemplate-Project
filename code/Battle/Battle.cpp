#include "Battle.h"

Battle::Battle(Country* c1, Country* c2, int t) : c1(c1), c1(c2), theatre(t) {}

void Battle::commence() {
    cout << "Battle commenced " << c1->getName << " VS " << c2->getName << endl;
}
