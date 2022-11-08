#ifndef PEACE_H
#define PEACE_H

#include "Phase.h"

class Peace : public Phase { 
    public :
        void handle(PhaseManager* pm, vector<Country*> countryArr, int i);
        string getPhase();
};

#endif