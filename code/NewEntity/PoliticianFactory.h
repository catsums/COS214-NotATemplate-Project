#ifndef POLITICIANFACTORY_H
#define POLITICIANFACTORY_H

#include "CitizenFactory.h"
#include "Citizen.h"

class PoliticianFactory : public CitizenFactory
{
private:
    /* data */
public:
    PoliticianFactory(/* args */);
    ~PoliticianFactory();
    Citizen *createPolitician(int, string, string);
};

#endif

