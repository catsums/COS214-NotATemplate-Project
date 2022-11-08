/** @file Army.h
 *  @brief Header for the Army class.
 *
 *  Army is used by country to store and mange all fighting troops that will be used in battle.
 * 
 */

#ifndef ARMY_H
#define ARMY_H

#include <string>

using namespace std;

class Army
{
    public:
        /** Constructor
         * @param int recources for initail recruitment
        */
        Army(int r);

        /** Recruits troops
         * @param int recources to be used for recruitment
        */
        void recruit(int r);

        /** Destroys troops
         * @param double percentage of casualties to suffer
        */
        void sufferCasualties(double cp);

        /** Accessor
        */
        int getStrength();
    private:
        int strength; /**<int Indicates how effective the army will be in a battle*/
};

#endif