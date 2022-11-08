#include "Army.h"

#include <iostream>

Army::Army(string c)
{
    strength = 0;

    armyType = new AllOutForce();

    citizenFactories.push_back(new SoldierFactory());
    citizenFactories.push_back(new MedicFactory());
    citizenFactories.push_back(new InformantFactory());

    vehicleFactories.push_back(new TransportFactory());
    vehicleFactories.push_back(new ArtilleryFactory());

    country = c;
}

int Army::recruit()
{
   

    int roll = myHelper::randomInt(0,6);

    int cost = 0;
    switch(roll){
        case 0: cost = recruitSoldier(); break;
        case 1: cost = recruitMedic(); break;
        case 2: cost = recruitInformant(); break;

        case 3: cost = createSeaVehicle(); break;
        case 4: cost = createLandVehicle(); break;
        case 5: cost = createAirVehicle(); break;
    }

    strength += cost / 2;

    return cost;
    
}

void Army::clearDead(){
    cout<<"Clearing the dead soldiers..."<<endl;
    bool theresDead = false;
    while(theresDead){
        theresDead = false;
        for(int i=0;i<(int)entities.size();i++){
            if(entities[i] && !entities[i]->isAlive()){
                removeEntity(entities[i]);
                strength--;
                theresDead = true;
                break;
            }
        }
    }
}

void Army::sufferCasualties(double cp)
{
    if(strength * cp < strength)
    {
        strength *= cp;
    }
}

int Army::getStrength()
{
    return strength;
}

Army::~Army(){
    armyType = NULL;
}

void Army::addEntity(Entity* ent){
    entities.push_back(ent);
    ent->setCountry(country);
}
Entity* Army::removeEntity(Entity* ent){
    Entity* removed = NULL;
    if(hasEntity(ent)){
        for(int i=0; i<(int)entities.size();i++){
            Entity* _ent = entities[i];
            if(!_ent) continue;
            if(ent == _ent || ent->getID() == _ent->getID()){
                removed = ent;
                ent->setCountry("");
                entities.erase(entities.begin()+i);
                break;
            }
        }
    }
    return removed;
}
bool Army::hasEntity(Entity* ent){
    if(ent){
        for(int i=0; i<(int)entities.size();i++){
            Entity* _ent = entities[i];
            if(!_ent) continue;
            if(_ent == ent || _ent->getID() == ent->getID()){
                return true;
            }
        }
    } 
    return false;
}

void Army::setForce(ArmyForce* force){
    armyType = force;
}
ArmyForce* Army::getForce(){
    return armyType;
}

int Army::recruitSoldier(){
    Entity* newEnt;
    
    newEnt = citizenFactories[0]->createCitizen();
    if(newEnt){
        addEntity(newEnt);
        return CITIZENCOST;
    }
    return 0;
}
int Army::recruitMedic(){
    Entity* newEnt;
    
    newEnt = citizenFactories[1]->createCitizen();
    if(newEnt){
        addEntity(newEnt);
        return CITIZENCOST;
    }
    return 0;
}
int Army::recruitInformant(){
    Entity* newEnt;
    
    newEnt = citizenFactories[2]->createCitizen();
    if(newEnt){
        addEntity(newEnt);
        return CITIZENCOST;
    }
    return 0;
}
int Army::createLandVehicle(){
    int roll = myHelper::randomInt(0,2);
    Entity* newEnt;
    
    if(roll<vehicleFactories.size()){
        newEnt = vehicleFactories[roll]->createLandVehicle();
        if(newEnt){
            addEntity(newEnt);
            return VEHICLECOST;
        }
    }
    return 0;
}
int Army::createSeaVehicle(){
    int roll = myHelper::randomInt(0,2);
    Entity* newEnt;
    
    if(roll<vehicleFactories.size()){
        newEnt = vehicleFactories[roll]->createSeaVehicle();
        if(newEnt){
            addEntity(newEnt);
            return VEHICLECOST;
        }
    }
    return 0;
}
int Army::createAirVehicle(){
    int roll = myHelper::randomInt(0,2);
    Entity* newEnt;
    
    if(roll<vehicleFactories.size()){
        newEnt = vehicleFactories[roll]->createAirVehicle();
        if(newEnt){
            addEntity(newEnt);
            return VEHICLECOST;
        }
    }
    return 0;
}
vector<Entity*> Army::getActiveForce(){
    vector<Entity*> force;
    if(armyType){
        force = armyType->getActiveForce(entities);
    }
    return force;
}
vector<Entity*> Army::getEntitiesByType(string type){
    vector<Entity*> ents;

    for(int i=0; i<(int)entities.size();i++){
        Entity* ent = entities[i];
        if(ent && ent->isType(type)){
            ents.push_back(ent);
        }
    }
    return ents;
}
Entity* Army::getRandomEntity(){
    Entity* ent = NULL;
    if(entities.size()){
        ent = myHelper::getRandomItemFrom<Entity*>(entities);
    }
    return ent;
}
