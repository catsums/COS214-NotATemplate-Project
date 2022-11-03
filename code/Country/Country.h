// ***************************
// compiled by Tanaka Humbani*
// Country class             *
// Needs: Citizen, Army      *
// ***************************

#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>
#include <string>
#include <vector>

// includes
#include "../NewEntity/Citizen.h"
#include "../NewResource/Resource.h"
#include "../Facility/Facility.h"
#include "../Army/Army.h"
#include "../Map/LandZone.h"
#include "../Map/SeaZone.h"
#include "../SignalHandler/SignalBus.h"

using namespace std;

class Country
{
    public:
        Country();
        Country(string n);
        ~Country();
        // void setTotalArmy(int);
        void setReserves(int);
        void setName(string);
        // void setStrength(double);
        void setAllies(Country**, int);
        void setAllies(vector<Country*>); //added by Cass
        void setEnemies(Country**, int);
        void setEnemies(vector<Country*>); //added by Cass

        Country** getAlliesAsArray(); // returns an array of type country.
        Country** getEnemiesAsArray(); // returns an array of type country.

        void print();
        // double getStrength();
        int getTotal();
        int getReserves();
        

        //added by Cassim
        bool isAlly(Country* c);
        bool isEnemy(Country* c);

        void addAlly(Country* c);
        void addEnemy(Country* c);

        string getName() const;
        // double getStrength() const;
        // int getTotalArmy() const;
        int getReserveCount() const;

        int getNumberOfAllies();
        int getNumberOfEnemies();

        vector<Country*>* getAllies(); // returns an array of type country.
        vector<Country*>* getEnemies(); // returns an array of type country.

        string getID() const;

        void addCitizen(Citizen* ctn);
        Citizen* removeCitizen(Citizen* ctn);
        bool hasCitizen(Citizen* ctn);

        void addFacility(Facility* fac);
        Facility* removeFacility(Facility* fac);
        bool hasFacility(Facility* fac);

        void addResource(Resource* reso);
        Resource* removeResource(Resource* reso);
        bool hasResource(Resource* reso);

        void addZone(Zone* zone);
        Zone* removeZone(Zone* zone);
        bool hasZone(Zone* zone);

        virtual string printInfo(){
            stringstream ss;

            ss << "COUNTRY-"<<getID();
            ss << "\n";
            ss << " Name: " << getName() << " | ";

            ss << "\n[";
            ss << getInfo();
            ss << "\n]";

            return ss.str();
        }

        virtual string getInfo(){
            stringstream ss;
            
            ss<<"\n\t Citizens:"<<"\n";
            for(auto const&ent :citizens){
                if(ent){
                    ss << ent->printInfo() << endl;
                }
            }

            ss<<"\n\t Facilities:"<<"\n";
            for(auto const&fac :facilities){
                if(fac){
                    ss << fac->printInfo() << endl;
                }
            }
            
            ss<<"\n\t Resources:"<<"\n";
            for(auto const&reso :resources){
                if(reso){
                    ss << reso->printInfo() << endl;
                }
            }

            ss<<"\n\t Zones:"<<"\n";
            for(auto const&zone :zones){
                if(zone){
                    ss << zone->printInfo() << endl;
                }
            }

            return ss.str();
        }
    private:
        string id;

        string name;
        // double strength;    //based on military size?
        vector<Country*> enemies;  // All the other countries that are not allies.
        vector<Country*> allies;   
        // Citizen politician; 
        Army army;
        // int totalArmy;
        int reserves;

        vector<Citizen*> citizens;

        vector<Resource*> resources;

        vector<Facility*> facilities;

        vector<Zone*> zones;

        SignalBus signalBus;
};
#endif
