#ifndef BATTLEVEHICLEFACTORY_H
#define BATTLEVEHICLEFACTORY_H

#include "VehicleFactory.h"
#include "BattleVehicle.h"

class BattleVehicleFactory : public VehicleFactory
{
private:
    /* data */
public:
    BattleVehicleFactory(/* args */);
    ~BattleVehicleFactory();
    virtual Entity* createEntity(int hp, string c){
        return new BattleVehicle(hp, c, 100);
    }
    virtual Entity* createEntity(int hp, string c, int f){
        return createVehicle(hp,c,f);
    }
    virtual Vehicle* createVehicle(int hp, string c, int f){
        return new BattleVehicle(hp, c, f);
    }
    virtual BattleVehicle* createBattleVehicle(int hp, string c, int f, int dmg){
        return new BattleVehicle(hp, c, f, dmg);
    }
    

};

#endif
