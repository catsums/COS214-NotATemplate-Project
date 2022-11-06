#ifndef DEPOT_H
#define DEPOT_H

#include "Depot.h"

using namespace std;

class Depot : public Facility
{
    public:
        Depot(int g);
        void displayFacility();

    private:
        int garages;
};

#endif