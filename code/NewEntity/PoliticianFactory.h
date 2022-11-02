#ifndef POLITICIANFACTORY_H
#define POLITICIANFACTORY_H

#include "CitizenFactory.h"
#include "Politician.h"

using namespace std;

class PoliticianFactory : public CitizenFactory
{
private:
    /* data */
public:
    PoliticianFactory(/* args */);
    ~PoliticianFactory();
    Entity* createEntity(int hp, string c){
        return new Politician(hp, c);
    }
    Politician* createPolitician(Citizen* ent, int amt){
        Politician* person = new Politician(*ent);
        
        return person;
    }
};

#endif

