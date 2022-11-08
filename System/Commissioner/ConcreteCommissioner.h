/** @file ConcreteCommissioner.h
 *  @brief Header for the ConcreteCommissioner class.
 *
 *  CocreteCommissioner is the concrete version of commissioner, used as part of the chain of responsibility.
 *  Also acts as the directer participant of the builder pattern
 */

#ifndef FOBCOMMISSIONER_H
#define FOBCOMMISSIONER_H

#include "Commissioner.h"

class ConcreteCommissioner : public Commissioner { 
    public:
        /** Constructor
         * @param int Available space for construction
        */
        ConcreteCommissioner(int t); 

        /** Requests construction of base
         * @param int number of buildings to be built
         * @param bool whether coast buildings must be built
        */
        void commission(int ft, bool coastal);
    private:
        int territory; /**<int Stores available space for construction*/
};

#endif