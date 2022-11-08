/** @file FOB.h
 *  @brief Header for the FOB class.
 *
 *  FOB represents a group of buildings that form a base.
 *  This class serves as the composite participant of the Composite pattern.
 */

#ifndef FOB_H
#define FOB_H

#include <vector>
#include "Facility.h"

using namespace std;

class FOB : public Facility
{
    public:
        /** Constructor
        */
        FOB();

        /** Prints information about the facility
        */
        void displayFacility();

        /** Adds a facility to the composite
         * @param Facility facility to be added
        */
        void addFacility(Facility* f);

        /** Removes a facility from the composite
        */
        void removeFacility();

        /** accessors
        */
        vector<Facility*> getFacilities();
        int getSpace();

    private:
        vector<Facility*> facilities; /**<vector holds an array of vectors*/
};

#endif