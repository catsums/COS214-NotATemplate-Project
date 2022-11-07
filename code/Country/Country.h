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
#include "../Entity/Entity.h"
#include "../Entity/Citizen.h"
// #include "../NewEntity/Politician.h"
// #include "../NewResource/Resource.h"
// #include "../Facility/Facility.h"
// #include "../Army/Army.h"
// #include "../Map/LandZone.h"
// #include "../Map/SeaZone.h"
#include "../SignalHandler/SignalBus.h"
// #include "../Army/AirForce.h"
// #include "../Army/NavalForce.h"
// #include "../Army/GroundForce.h"

using namespace std;

class Country
{
    public:
        Country();
        Country(string n);
        ~Country();

        void setName(string);

        void print();

        string getName() const;

        string getID() const;

        
        vector<Citizen*> getCitizens(){
            vector<Citizen*> citizens;

            for(int i=0;i<(int)entities.size();i++){
                Entity* ent = entities[i];
                if(ent->isType("Citizen")){
                    try{
                        Citizen* cit = static_cast<Citizen*>(ent);
                        citizens.push_back(cit);
                    }catch(const bad_cast& err){
                        cout<<"Couldn't cast Entity to Citizen"<<endl;
                    }
                }
            }

            return citizens;
        }
        vector<Citizen*> getTroops(){
            vector<Citizen*> troops;
            vector<Citizen*> cits = getCitizens();

            for(int i=0;i<(int)cits.size();i++){
                Citizen* ent = cits[i];
                if(ent->isType("Soldier")){
                    troops.push_back(ent);
                }else if(ent->isType("Medic")){
                    troops.push_back(ent);
                }
            }

            return troops;
        }

        void addEntity(Entity* ctn);
        Entity* removeEntity(Entity* ctn);
        bool hasEntity(Entity* ctn);

        vector<Entity*> getEntities(){
            return entities;
        }

        // void addFacility(Facility* fac);
        // Facility* removeFacility(Facility* fac);
        // bool hasFacility(Facility* fac);

        // vector<Facility*> getFacilities(){
        //     return facilities;
        // }

        // void addResource(Resource* reso);
        // Resource* removeResource(Resource* reso);
        // bool hasResource(Resource* reso);

        // vector<Resource*> getResources(){
        //     return resources;
        // }

        // void addZone(Zone* zone);
        // Zone* removeZone(Zone* zone);
        // bool hasZone(Zone* zone);

        void runProductions(){
            
        }

        // void useHospital(){
        //     Facility* hospital = getFacilityByType("Hospital");
        //     if(hospital){
        //         try{
        //             Hospital* fac = static_cast<Hospital*>(hospital);
        //             vector<Citizen*> citizens = getCitizens();
        //             for(int i=0;i<(int)citizens;i++){
        //                 Entity* ent = citizens[i];
        //                 fac->healCitizen(ent);
        //             }
        //         }catch(const& bad_cast err){
        //             cout<<"Couldn't cast Facility to Hospital"<<endl;
        //         }
        //     }
        // }
        // void useFortification(){
        //     Facility* fort = getFacilityByType("Fortification");
        //     if(fort){
        //         try{
        //             Fortification* fac = static_cast<Fortification*>(fort);
        //             vector<Citizen*> citizens = getTroops();
        //             for(int i=0;i<(int)citizens;i++){
        //                 Entity* ent = citizens[i];
        //                 fac->healCitizen(ent);
        //             }
        //         }catch(const& bad_cast err){
        //             cout<<"Couldn't cast Facility to Fortification"<<endl;
        //         }
        //     }
        // }

        // Facility* getFacilityByType(string type){
        //     for(int i=0;i<(int)zones.size();i++){
        //         Zone* zone = zones[i];
        //         vector<Facility*> facs = zone->getFacilities();
        //         for(int j=0;j<(int)facs.size();j++){
        //             Facility* fac = facs[i];
        //             if(fac->isType(type)){
        //                 return fac;
        //             }
        //         }
        //     }
        //     return NULL;
        // }

        // vector<Zone*> getZones(){
        //     return zones;
        // }

        // ArmyForce* getLandForce(){
        //     vector<Entity*> army;
        //     for(int i=0; i<(int)entities.size();i++){
        //         Entity* ent = entities[i];
        //         if(ent->canTravelLand()){
        //             army.push_back(ent);
        //         }
        //     }

        //     ArmyForce* force = new GroundForce(army);
        //     return force;
        // }
        // ArmyForce* getSeaForce(){
        //     vector<Entity*> army;
        //     for(int i=0; i<(int)entities.size();i++){
        //         Entity* ent = entities[i];
        //         if(ent->canTravelSea()){
        //             army.push_back(ent);
        //         }
        //     }

        //     ArmyForce* force = new NavalForce(army);
        //     return force;
        // }
        // ArmyForce* getAirForce(){
        //     vector<Entity*> army;
        //     for(int i=0; i<(int)entities.size();i++){
        //         Entity* ent = entities[i];
        //         if(ent->canTravelLand() && ent->canTravelSea()){
        //             army.push_back(ent);
        //         }
        //     }

        //     ArmyForce* force = new AirForce(army);
        //     return force;
        // }



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
            
            ss<<"\n\t Entities:"<<"\n";
            for(auto const&ent :entities){
                if(ent){
                    // ss << ent->printInfo() << endl;
                    ent->infoSummary();
                }
            }

            // ss<<"\n\t Facilities:"<<"\n";
            // for(auto const&fac :facilities){
            //     if(fac){
            //         ss << fac->printInfo() << endl;
            //     }
            // }
            
            // ss<<"\n\t Resources:"<<"\n";
            // for(auto const&reso :resources){
            //     if(reso){
            //         ss << reso->printInfo() << endl;
            //     }
            // }

            // ss<<"\n\t Zones:"<<"\n";
            // for(auto const&zone :zones){
            //     if(zone){
            //         ss << zone->printInfo() << endl;
            //     }
            // }

            return ss.str();
        }
    private:
        string id;

        string name;   
        // Citizen* politician;

        vector<Entity*> entities;

        // vector<Resource*> resources;

        // vector<Zone*> zones;

        SignalBus signalBus;
};
#endif
