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

class Army{
protected:
    ArmyForce* armyType;
    vector<Entity*> entities;

    vector<CitizenFactory*> citizenFactories;
    vector<VehicleFactory*> vehicleFactories;

    static const int VEHICLECOST = 5;
    static const int CITIZENCOST = 2;

    string country;

public:
    friend class Country;
    Army(string c);
    ~Army();
    
    void addEntity(Entity* ent);
    Entity* removeEntity(Entity* ent);
    bool hasEntity(Entity* ent);
    void setForce(ArmyForce* force);
    ArmyForce* getForce();

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

};

#endif

