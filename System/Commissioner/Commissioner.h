/** @file Commissioner.h
 *  @brief Header for the Commissioner class.
 *
 *  Commissioner is the abstract parent class that forms part of the chain of responsibility pattern as the handler participant
 */

#ifndef COMMISSIONER_H
#define COMMISSIONER_H

#include <vector>

#include "../Facility/FOB.h"

class Commissioner { 
    public :
        /** Constructor
        */
        Commissioner();

        /** Adds another handler to the chain
         * @param Commissioner handler reference
        */
        void add(Commissioner *n);

        /** Requests construction of base
         * @param int number of buildings to be built
         * @param bool whether coast buildings must be built
        */
        virtual void commission(int i, bool coastal);

        /** Returns info related to groups of constructed bases
         * @param vector Building group
         * @param Commissioner the commisioner that must evaluate
        */
        virtual void getInfo(vector<FOB*> f, Commissioner* c);

        /** Returns excess space after construction
        */
        int getLeftOver();

        /** Mutator
         * @param FOB input
        */
        void setFacilities(FOB* fob);

        /** Accessor
        */
        vector<FOB*> getFacilities();
    private : 
        Commissioner* next; /**<Commissioner reference to next handler in the chain*/
        int leftOver; /**<int Stores excess space after construction*/
        vector<FOB*> facilities; /**<vector Stores constructed facilites*/
};

#endif