#ifndef PHASE_H
#define PHASE_H

#include <iostream>
#include <vector>

#include "../Country/Country.h"

class PhaseManager;
//#include "PhaseManager.h"

using namespace std;

class Phase { 
    public: 
        virtual void handle(PhaseManager* pm, vector<Country*> countryArr, int i) = 0;
        virtual string getPhase() = 0;
};

#endif