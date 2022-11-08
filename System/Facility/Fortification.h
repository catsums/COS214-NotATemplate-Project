#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include "Facility.h"

using namespace std;

class Fortification : public Facility
{
    public:
        Fortification(int l);
        void displayFacility();
        int getDefenseLevel();

    private:
        int defenseLevel;
};

#endif