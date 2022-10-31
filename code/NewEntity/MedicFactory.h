#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "CitizenFactory.h"
#include "Citizen.h"


class MedicFactory : public CitizenFactory
{
private:
    /* data */
public:
    MedicFactory(/* args */);
    ~MedicFactory();
    Citizen* createMedic(int, string, string);
};
#endif