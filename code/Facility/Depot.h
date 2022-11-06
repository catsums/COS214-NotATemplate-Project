#ifndef DEPOT_H
#define DEPOT_H

#include "Facility.h"

using namespace std;

class Depot : public Facility
{
    public:
        Depot(int g);
        void displayFacility();
        int getGarages();

    private:
        int garages;
};

#endif