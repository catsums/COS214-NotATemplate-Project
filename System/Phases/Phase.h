#ifndef PHASE_H
#define PHASE_H

#include <iostream>

#include "../WarEngine/WarEngine.h"
#include "PhaseManager.h"

using namespace std;

class Phase { 
    public: 
        virtual void handle(PhaseManager* pm, vector<Country*> countryArr, int i) = 0;
        virtual string getPhase() = 0;
        virtual  ~Phase();
};

#endif