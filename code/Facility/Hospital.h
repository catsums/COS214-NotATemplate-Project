#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Facility.h"

using namespace std;

class Hospital : public Facility
{
    public:
        Hospital(int c, int l);
        void displayFacility();

    private:
        int capacity;
        int techLevel;
};

#endif