#ifndef NEGOTIATIONS_H
#define NEGOTIATIONS_H

#include "Phase.h"

class Negotiations : public Phase { 
    public :
        void handle(PhaseManager* pm, vector<Country*> countryArr, int i);
        string getPhase();
};

#endif