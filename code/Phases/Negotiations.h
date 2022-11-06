#ifndef NEGOTIATIONS_H
#define NEGOTIATIONS_H

#include "Phase.h"

class Negotiations : public Phase { 
    public :
        virtual void handle(WarEngine* w);
        virtual string getPhase(); 
};

#endif