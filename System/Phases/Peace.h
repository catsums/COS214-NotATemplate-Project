#ifndef PEACE_H
#define PEACE_H

#include "Phase.h"

class Peace : public Phase { 
    public :
        virtual void handle(WarEngine* w);
        virtual string getPhase(); 
};

#endif