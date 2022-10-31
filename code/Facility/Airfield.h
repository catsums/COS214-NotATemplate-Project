#ifndef AIRFIELD_H
#define AIRFIELD_H

#include "Facility.h"

using namespace std;

class Airfield : public Facility
{
    public:
        Airfield(int r, int h);
        void displayFacility();

    private:
        int runways;
        int hangers;
};

#endif