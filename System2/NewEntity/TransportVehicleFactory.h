#ifndef BATTLEVEHICLEFACTORY_H
#define BATTLEVEHICLEFACTORY_H

#include "VehicleFactory.h"
#include "TransportVehicle.h"

class TransportVehicleFactory : public VehicleFactory
{
private:
    /* data */
public:
    TransportVehicleFactory(/* args */);
    ~TransportVehicleFactory();
    virtual Entity* createEntity(int hp, string c){
        return new TransportVehicle(hp, c, 100);
    }
    virtual Entity* createEntity(int hp, string c, int f){
        return createVehicle(hp,c,f);
    }
    virtual Vehicle* createVehicle(int hp, string c, int f){
        return new TransportVehicle(hp, c, f);
    }
    virtual TransportVehicle* createTransportVehicle(int hp, string c, int f){
        return new TransportVehicle(hp, c, f);
    }
    

};

#endif
