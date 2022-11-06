#ifndef PORT_H
#define PORT_H

#include "Port.h"

using namespace std;

class Port : public Facility
{
    public:
        Port(int d);
        void displayFacility();

    private:
        int docks;
};

#endif