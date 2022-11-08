/** @file Phase.h
 *  @brief Header for the Phase class.
 *
 *  Parent class for phases, all other phases inherit from this
 */

#ifndef PHASE_H
#define PHASE_H

#include <iostream>
#include <vector>

#include "../Country/Country.h"

class PhaseManager;
//#include "PhaseManager.h"

using namespace std;

class Phase { 
    public: 
        /** Handle function for a given phase
         * @param PhaseManager reference to context
         * @param vector array of countries
         * @param int current country being used
        */
        virtual void handle(PhaseManager* pm, vector<Country*> countryArr, int i) = 0;

        /** Returns a string showing the current phase
        */
        virtual string getPhase() = 0;
};

#endif