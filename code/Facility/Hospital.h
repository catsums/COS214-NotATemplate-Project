#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Facility.h"
#include "../NewEntity/Citizen.h"

using namespace std;

class Hospital : public Facility
{
    public:
        Hospital(int cap, int lvl);
        Hospital(string c, int cap, int lvl);
        void displayFacility();

        void healCitizen(Citizen* ent){
            if(ent){
                ent->heal(10 * techLevel);
            }
        }

    private:
        int capacity;
        int techLevel;
};

#endif