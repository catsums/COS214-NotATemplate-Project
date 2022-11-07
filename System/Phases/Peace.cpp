#include <iostream>
#include "Peace.h"

using namespace std;

void Peace::handle(WarEngine* w, vector<Country*> countryArr, int i) {
    cout << "Country is not at war" << endl;
}

string Peace::getPhase() {
    return "Peace";
}