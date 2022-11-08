/** @file Army.h
 *  @brief Header for the Army class.
 *
 *  Army is used by country to store and mange all fighting troops that will be used in battle.
 * 
 */

#ifndef ARMY_H
#define ARMY_H

#include <iostream>
#include <string>
#include <vector>

#include "../Entity/Entity.h"
#include "../Entity/SoldierFactory.h"
#include "../Entity/MedicFactory.h"
#include "../Entity/InformantFactory.h"
#include "../Entity/PoliticianFactory.h"
#include "../Entity/TransportFactory.h"
#include "../Entity/ArtilleryFactory.h"
#include "ArmyForce.h"
#include "AllOutForce.h"
#include "../myHelper.cpp"

using namespace std;

class Army
{
    public:
        /** Constructor
         * @param string for country name 
         * @param int recources for initail recruitment
        */
        Army(string c);
        ~Army();
        /** Recruits troops
         * @param int recources to be used for recruitment
        */
        int recruit();
        void clearDead();

        /** Destroys troops
         * @param double percentage of casualties to suffer
        */
        void sufferCasualties(double cp);

        /** Accessor
        */
        int getStrength();

        void addEntity(Entity* ent);
        Entity* removeEntity(Entity* ent);
        bool hasEntity(Entity* ent);
        void setForce(ArmyForce* force);
        ArmyForce* getForce();

        vector<Entity*> getEntities(){
            return entities;
        }

        int recruitSoldier();
        int recruitMedic();
        int recruitInformant();
        int createLandVehicle();
        int createSeaVehicle();
        int createAirVehicle();
        vector<Entity*> getActiveForce();

        vector<Entity*> getEntitiesByType(string type);
        Entity* getRandomEntity();

        string getCountry(){
            return country;
        }
    protected:
        int strength; /**<int Indicates how effective the army will be in a battle*/
        ArmyForce* armyType;
        vector<Entity*> entities;

        vector<CitizenFactory*> citizenFactories;
        vector<VehicleFactory*> vehicleFactories;

        static const int VEHICLECOST = 5;
        static const int CITIZENCOST = 2;

        string country;
};

#endif