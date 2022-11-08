#ifndef FOB_H
#define FOB_H

#include <vector>
#include "Facility.h"

using namespace std;

class FOB : public Facility
{
    public:
        FOB();
        void displayFacility();
        void addFacility(Facility* f);
        void removeFacility();

        vector<Facility*> getFacilities();
        int getSpace();

    private:
        vector<Facility*> facilities;
};

#endif