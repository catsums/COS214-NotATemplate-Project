#ifndef COMMISSIONER_H
#define COMMISSIONER_H

#include <vector>

#include "../Facility/FOB.h"

class Commissioner { 
    public :
        Commissioner();
        void add(Commissioner *n);
        virtual void commission(int i, bool coastal);
        int getLeftOver();
        vector<FOB*> getFacilities();
    private : 
        Commissioner* next;
        int leftOver;
        vector<FOB*> facilities;
};

#endif