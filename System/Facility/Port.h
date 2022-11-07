#ifndef PORT_H
#define PORT_H

#include "Facility.h"

using namespace std;

class Port : public Facility
{
    public:
        Port(int d);
        void displayFacility();
        int getDocks();

    private:
        int docks;
};

#endif