#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include "CitizenFactory.h"
#include "Citizen.h"
#include "Medic.h"


class MedicFactory : public CitizenFactory
{
private:
    /* data */
public:
    MedicFactory(/* args */){}
    ~MedicFactory(){}
    Entity* createEntity(int hp, string c){
        return new Medic(hp, c);
    }
    Medic* createMedic(Citizen* ent, int amt){
        Medic* person = new Medic(ent);
        person->setHealingAmt(amt);
        return person;
    }
};
#endif