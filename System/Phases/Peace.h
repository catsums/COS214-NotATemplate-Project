/** @file Peace.h
 *  @brief Header for the Peace class.
 *
 *  Peace is one of the three phases that the program can be in
 *  It serves as the terminating phase for the war
 */

#ifndef PEACE_H
#define PEACE_H

#include "Phase.h"

class Peace : public Phase { 
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