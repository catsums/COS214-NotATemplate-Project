// ***************************
// compiled by Tanaka Humbani*
// Country class             *
// Needs: Citizen, Army      *
// ***************************

#ifndef COUNTRY_H
#define COUNTRY_H

// includes
// #include "Citizen.h"
#include "Army.h"

#include <string>
#include <vector>

using namespace std;

class Country
{
    public:
        void setTotalArmy(int);
        void setReserves(int);
        void setName(string);
        void setStrength(double);
        void setAllies(Country**, int);
        void setAllies(vector<Country*>); //added by Cass
        void setEnemies(Country**, int);
        void setEnemies(vector<Country*>); //added by Cass

        Country** getAlliesAsArray(); // returns an array of type country.
        Country** getEnemiesAsArray(); // returns an array of type country.

        void print();
        double getStrength();
        int getTotal();
        int getReserves();
        Country();
        Country(string n);
        ~Country();

        //added by Cassim
        bool isAlly(Country* c);
        bool isEnemy(Country* c);

        void addAlly(Country* c);
        void addEnemy(Country* c);

        string getName() const;
        double getStrength() const;
        int getTotalArmy() const;
        int getReserveCount() const;

        int getNumberOfAllies();
        int getNumberOfEnemies();

        vector<Country*>* getAllies(); // returns an array of type country.
        vector<Country*>* getEnemies(); // returns an array of type country.

        string getID() const;
        void setNavyTroops(int t);
        void setGroundTroops(int t);
        void setAirTroops(int t);

        int getNavyTroops();
        int getGroundTroops();
        int getAirTroops();

    private:
        string id;
        int navyTroops;
        int groundTroops;
        int airTroops;
        string name;
        double strength;    //based on military size?
        vector<Country*> enemies;  // All the other countries that are not allies.
        vector<Country*> allies;   
        // Citizen politician; 
        Army Defense;
        int totalArmy;
        int reserves;
};
#endif
