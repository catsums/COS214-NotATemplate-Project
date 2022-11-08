/** @file Negotiations.h
 *  @brief Header for the Negotiations class.
 *
 *  Negotiations is one of the three phases that the program can be in
 *  It serves as a point in the war where peace could potentially be achieved.
 */

#ifndef NEGOTIATIONS_H
#define NEGOTIATIONS_H

#include "Phase.h"

class Negotiations : public Phase { 
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