#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include "EntityFactory.h"
#include "Entity.h"

class CitizenFactory : public EntityFactory
{
private:
    /* data */
public:
    CitizenFactory(/* args */);
    ~CitizenFactory();
    Entity* createCitizen(int, string, string);

};

#endif
