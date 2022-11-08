#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include "Facility.h"

using namespace std;

class Fortification : public Facility
{
    public:
        Fortification(int l);
        Fortification(int l, string c);
        void displayFacility();

    private:
        int defenseLevel;
};

#endif