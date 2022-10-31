#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "CitizenFactory.h"
#include "Citizen.h"

class SoldierFactory : public CitizenFactory
{
private:
    /* data */
public:
    SoldierFactory(/* args */);
    ~SoldierFactory();
    Citizen *createSoldier(int, string, string);
};

#endif