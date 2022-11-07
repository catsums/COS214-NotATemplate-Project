#ifndef NEGOTIATIONS_H
#define NEGOTIATIONS_H

#include "Phase.h"

class Negotiations : public Phase { 
    public :
        void handle(WarEngine* w, vector<Country*> countryArr, int i);
        string getPhase(); 
};

#endif