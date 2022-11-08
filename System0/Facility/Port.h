/** @file Port.h
 *  @brief Header for the Port class.
 *
 *  Port represents buildings that can store sea vehicles.
 *  This class serves as a leaf participant of the Composite pattern.
 */

#ifndef PORT_H
#define PORT_H

#include "Facility.h"

using namespace std;

class Port : public Facility
{
    public:
        /** Constructor
         * @param int input parameter
        */
        Port(int d);
        ~Port();

        /** Prints information about the facility
        */
        void displayFacility();

        /** accessor
        */
        int getDocks();

    private:
        int docks; /**<int holds primary facility property*/
};

#endif