/** @file Depot.h
 *  @brief Header for the Depot class.
 *
 *  Depot represents buildings that can store ground vehicles.
 *  This class serves as a leaf participant of the Composite pattern.
 */

#ifndef DEPOT_H
#define DEPOT_H

#include "Facility.h"

using namespace std;

class Depot : public Facility
{
    public:
        /** Constructor
         * @param int input parameter
        */
        Depot(int g);
        ~Depot();

        /** Prints information about the facility
        */
        void displayFacility();

        /** accessor
        */
        int getGarages();

    private:
        int garages; /**<int holds primary facility property*/
};

#endif