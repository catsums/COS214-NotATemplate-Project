#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Facility.h"

using namespace std;

class Hospital : public Facility
{
    public:
        Hospital(int c);
        void displayFacility();
        int getCapacity();

    private:
        int capacity;
};

#endif