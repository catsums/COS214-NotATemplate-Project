#ifndef PHASEMANAGER_H
#define PHASEMANAGER_H

#include <iostream>

#include "Peace.h"
#include "Negotiations.h"
#include "War.h"

using namespace std;

class PhaseManager { 
    public: 
        PhaseManager(WarEngine* w);
        ~PhaseManager();
        
        void DecideAction(vector<Country*> countryArr, int i);
        void setPhase(Phase* p);

        WarEngine* w;
    private: 
        Phase* phase;
};

#endif