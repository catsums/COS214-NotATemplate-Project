#ifndef AIRFIELD_H
#define AIRFIELD_H

#include "Facility.h"

using namespace std;

class Airfield : public Facility
{
    public:
        Airfield(int h);
        void displayFacility();
        int getHangers();

    private:
        int hangers;
};

#endif