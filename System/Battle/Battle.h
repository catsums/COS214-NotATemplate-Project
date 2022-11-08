/** @file Battle.h
 *  @brief Header for the Battle class.
 *
 *  Battle is the class that gets created whenever a country gets into physical conflict with another country.
 *  Battle will simulate the battle between the countries and generate results based on the armies of the country.
 */

#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "../Country/Country.h"

using namespace std;

class Battle
{
    public:
        /** Constructor
         * @param Country attacking country
         * @param Country defending country
         * @param int theatre to be used for the battle
        */
        Battle(Country* c1, Country* c2, int t);

        /** Destructor
        */
        ~Battle();

        /** Starts the battle simulation
        */
        void commence();

        /** Determines the results of the battle
        */
        void determineOutcome();
    private:
        Country* c1; /**<Country Attacking country*/
        Country* c2; /**<Country Defending country*/
        int theatre; /**<int Stores theatre to be used for the battle*/
};

#endif