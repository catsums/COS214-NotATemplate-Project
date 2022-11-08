/** @file BaseBuilder.h
 *  @brief Header for the BaseBuilder class.
 *
 *  BaseBuilder is used to construct FOB composites.
 *  BaseBuilder acts as the builder participant of the builder pattern
 */

#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <string>
#include "../Facility/FOB.h"
#include "../Facility/Airfield.h"
#include "../Facility/Depot.h"
#include "../Facility/Fortification.h"
#include "../Facility/Hospital.h"
#include "../Facility/Port.h"

using namespace std;

class BaseBuilder
{
    public:
        /** Constructor
         * @param int how many facilities this FOB will contain
         * @param bool indicates if coastal
        */
        BaseBuilder(int baseN, bool c);

        /** Returns the constructed FOB
        */
        FOB* getResult();
    private:
        int baseN; /**<int Indicates how many facilities this FOB will contain*/
        FOB* newBase; /**<FOB Holds the FOB currently being built*/
        
};

#endif