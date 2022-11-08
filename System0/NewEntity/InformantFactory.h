#ifndef INFORMANTFACTORY_H
#define INFORMANTFACTORY_H

#include "CitizenFactory.h"
#include "Informant.h"

using namespace std;

class InformantFactory : public CitizenFactory
{
private:
    /* data */
public:
    InformantFactory(/* args */);
    ~InformantFactory();
    Entity* createEntity(int hp, string c){
        return new Informant(hp, c);
    }
    Informant* createInformant(Citizen* ent, int amt){
        Informant* person = new Informant(*ent);
        
        return person;
    }
};

#endif
