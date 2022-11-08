/** @file Hospital.h
 *  @brief Header for the Hospital class.
 *
 *  Hospital represents buildings that provide recovery facilites for injured solidiers.
 *  This class serves as a leaf participant of the Composite pattern.
 */

#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Facility.h"

using namespace std;

class Hospital : public Facility
{
    public:
        /** Constructor
         * @param int input parameter
        */
        Hospital(int c);
        ~Hospital();

        /** Prints information about the facility
        */
        void displayFacility();

        /** accessor
        */
        int getCapacity();

    private:
        int capacity; /**<int holds primary facility property*/
};

#endif