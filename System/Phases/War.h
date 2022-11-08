#ifndef WAR_H
#define WAR_H

#include "../Commissioner/ConcreteCommissioner.h"
#include "PhaseManager.h"
#include "Phase.h"

class War : public Phase { 
    public :
        void handle(PhaseManager* pm, vector<Country*> countryArr, int i);
        string getPhase();
};

#endif