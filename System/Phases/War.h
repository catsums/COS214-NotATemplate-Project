/** @file War.h
 *  @brief Header for the War class.
 *
 *  War is one of the three phases that the program can be in
 *  It provides actions for active conflict.
 */

#ifndef WAR_H
#define WAR_H

#include "../Commissioner/ConcreteCommissioner.h"
#include "PhaseManager.h"
#include "Phase.h"

class War : public Phase { 
    public :
        /** Handle function for this phase
         * @param PhaseManager reference to context
         * @param vector array of countries
         * @param int current country being used
        */
        void handle(PhaseManager* pm, vector<Country*> countryArr, int i);

        /** Returns a string showing the current phase
        */
        string getPhase();
};

#endif