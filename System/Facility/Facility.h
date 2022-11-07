#ifndef FACILITY_H
#define FACILITY_H

using namespace std;

class Facility
{
    public:
        virtual void displayFacility() = 0;

    protected:
        virtual int getHangers();
        virtual int getGarages();
        virtual int getDefenseLevel();
        virtual int getCapacity();
        virtual int getDocks();

};

#endif