#ifndef WAR_H
#define WAR_H

#include "Phase.h"

class War : public Phase { 
    public :
        virtual void handle(WarEngine* w, vector<Country*> countryArr, int i);j
        virtual string getPhase(); 
};

#endif