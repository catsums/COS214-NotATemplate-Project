#ifndef FACILITY_H
#define FACILITY_H

using namespace std;

class Facility
{
    public:
        virtual void displayFacility() = 0;

    protected:
        int getHangers();
        int getGarages();
        int getDefenseLevel();
        int getCapacity();
        int getDocks();

};

#endif