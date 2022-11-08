/** @file FOB.h
 *  @brief Header for the FOB class.
 *
 *  FOB represents a group of buildings that form a base.
 *  This class serves as the composite participant of the Composite pattern.
 */

#ifndef FOB_H
#define FOB_H

#include <iostream>
#include <vector>
#include "Facility.h"

using namespace std;

class FOB : public Facility
{
    public:
        /** Constructor
        */
        FOB();
        ~FOB();

        /** Prints information about the facility
        */
        void displayFacility();

        /** Adds a facility to the composite
         * @param Facility facility to be added
        */
        void addFacility(Facility* f);

        /** Removes a facility from the composite
        */
        Facility* removeFacility();

        /** accessors
        */
        vector<Facility*> getFacilities();
        int getSpace();

    private:
        vector<Facility*> facilities; /**<vector holds an array of vectors*/
};

#endif