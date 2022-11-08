#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "EntityFactory.h"
#include "Entity.h"
#include "Vehicle.h"

class VehicleFactory : public EntityFactory
{
private:
    /* data */
public:
    VehicleFactory(/* args */);
    ~VehicleFactory();
    virtual Entity* createEntity(int hp, string c){
        return new Vehicle(hp, c, 100);
    }
    virtual Entity* createEntity(int hp, string c, int f){
        return createVehicle(hp, c, f);
    }
    virtual Vehicle* createVehicle(int hp, string c, int f){
        return new Vehicle(hp, c, f);
    }
    

};

#endif
