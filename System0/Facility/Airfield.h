/** @file Airfield.h
 *  @brief Header for the Airfield class.
 *
 *  Airfield represents buildings that can store aircraft.
 *  This class serves as a leaf participant of the Composite pattern.
 */

#ifndef AIRFIELD_H
#define AIRFIELD_H

#include "Facility.h"

using namespace std;

class Airfield : public Facility
{
    public:
        /** Constructor
         * @param int input parameter
        */
        Airfield(int h);
        ~Airfield();

        /** Prints information about the facility
        */
        void displayFacility();

        /** accessor
        */
        int getHangers();

    private:
        int hangers; /**<int holds primary facility property*/
};

#endif