#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include "EntityFactory.h"
#include "Citizen.h"

using namespace std;

class CitizenFactory : public EntityFactory
{
private:
    /* data */
public:
    CitizenFactory(/* args */){
    
    }
    ~CitizenFactory();
    virtual Entity* createEntity(int hp, string c){
        return new Citizen(hp, c);
    }
    

};

#endif
