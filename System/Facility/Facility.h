/** @file Facility.h
 *  @brief Header for the Facility class.
 *
 *  Facility represents any building used in the war.
 *  This class serves as the component participant of the Composite pattern.
 */

#ifndef FACILITY_H
#define FACILITY_H

using namespace std;

class Facility
{
    public:
        /** Prints information about the facility
        */
        virtual void displayFacility() = 0;

    protected:
        /** accessors
        */
        virtual int getHangers();
        virtual int getGarages();
        virtual int getDefenseLevel();
        virtual int getCapacity();
        virtual int getDocks();

};

#endif