#ifndef PEACE_H
#define PEACE_H

#include "Phase.h"

class Peace : public Phase { 
    public :
        virtual void handle(WarEngine* w, vector<Country*> countryArr, int i);
        virtual string getPhase(); 
};

#endif