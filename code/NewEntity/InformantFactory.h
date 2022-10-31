#ifndef INFORMANTFACTORY_H
#define INFORMANTFACTORY_H

#include "CitizenFactory.h"
#include "Citizen.h"

class InformantFactory : public CitizenFactory
{
private:
    /* data */
public:
    InformantFactory(/* args */);
    ~InformantFactory();
    Citizen *createInformant(int, string, string);
};

#endif
