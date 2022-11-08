/** @file Fortification.h
 *  @brief Header for the Fortification class.
 *
 *  Fortification represents buildings that provide additional defenses to the base.
 *  This class serves as a leaf participant of the Composite pattern.
 */

#ifndef FORTIFICATION_H
#define FORTIFICATION_H

#include "Facility.h"

using namespace std;

class Fortification : public Facility
{
    public:
        /** Constructor
         * @param int input parameter
        */
        Fortification(int l);

        /** Prints information about the facility
        */
        void displayFacility();

        /** accessor
        */
        int getDefenseLevel();

    private:
        int defenseLevel; /**<int holds primary facility property*/
};

#endif