/** @file Country.h
 *  @brief Header for the Country class.
 *
 *  Country serves as the main class for defining all parameters related to each faction participating in the war.
 *  Countries maintain armies as well as variables related to them.
 */

#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include "../Facility/FOB.h"
#include "../Army/Army.h"

using namespace std;

class Country
{
    public:
        /** Constructor
         * @param string name of country
         * @param bool country's chosen side
         * @param bool shows if country is coastal
        */
        Country(string n, bool s, bool c);

        /** Destructor
        */
        ~Country();

        /** Generates resources for the country based on territory owned
        */
        int generateResources();

        /** calls the armies recruit function
        */
        void recruit();
        
        /** Used to adjust resource values up or down
         * @param int amount to adjust by
        */
        void updateResources(int u);

        /** Used to adjust territory values up or down
         * @param int amount to adjust by
        */
        void updateTerritory(int t, int fs);

        /** Adds FOBs to the bases variable
         * @param vector FOBs to be added
        */
        void addBases(vector<FOB*> nb);

        /** Check if bases are within capacity, if not destroy bases
        */
        void checkBaseCapacity();

        /** Calculate how much space the bases occupy
        */
        int baseSpace();
        
        /** Accessors
        */
        bool getSide();
        string getName();
        bool getCoastal();
        int getResources();
        int getTerritory();
        int getFreeSpace();
        Army* getArmy();

        /** Mutator
        */
        void setSide(bool s);
    private:
        Army* cArmy; /**<Army holds a refernce to the country's army*/
        vector<FOB*> bases; /**<vector stores all of the bases that the country owns*/
        bool side; /**<bool indicates which side the country fights for*/
        bool coastal; /**<bool indicates if the country is coastal or not*/
        string name; /**<string holds country name*/
        int resources; /**<int holds resources property*/
        int territory; /**<int holds territory property*/
        int freeSpace; /**<int holds freeSpace property which is how nuch territory isnt used*/
};

#endif