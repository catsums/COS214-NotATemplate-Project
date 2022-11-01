#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Facility.h"

using namespace std;

class Hospital : public Facility
{
    public:
        Hospital(int cap, int lvl);
        Hospital(string c, int cap, int lvl);
        void displayFacility();

    private:
        int capacity;
        int techLevel;
};

#endif