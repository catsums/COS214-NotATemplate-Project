// ***************************
// compiled by Tanaka Humbani*
// Country class             *
// Needs: Citizen, Army      *
// ***************************

#ifndef COUNTRY_H
#define COUNTRY_H

// includes
// #include "Citizen.h"
// #include "Army.h"

#include <string>

using namespace std;

class Country
{
    public:
        void setTotalArmy(int);
        void setReserves(int);
        void setName(string);
        void setStrength(double);
        void setAllies(Country*, int);
        void setEnemies(Country*, int);
        Country* getAllies(); // returns an array of type country.
        void print();
        double getStrength();
        int getTotal();
        int getReserves();
        Country();
        ~Country();

    private:
        string name;
        double strength;    //based on military size?
        Country *enemies;  // All the other countries that are not allies.
        Country *allies;   
        // Citizen politician; 
        // Army Defense;
        int totalArmy;
        int reserves;
};
#endif
