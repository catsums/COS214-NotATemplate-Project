#ifndef PHASE_H
#define PHASE_H

#include "Phase.h"

class Peace : public Phase { 
    public :
        virtual void handle(WarEngine* w);
        virtual string getPhase(); 
};

#endif