#ifndef WAR_H
#define WAR_H

#include "Phase.h"

class War : public Phase { 
    public :
        void handle(WarEngine* w, vector<Country*> countryArr, int i);
        string getPhase(); 
};

#endif