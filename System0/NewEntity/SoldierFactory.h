#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include "CitizenFactory.h"
#include "Soldier.h"

using namespace std;

class SoldierFactory : public CitizenFactory
{
private:
    /* data */
public:
    SoldierFactory(/* args */):CitizenFactory(){
        
    }
    ~SoldierFactory(){

    }
    Entity* createEntity(int hp, string c){
        return new Soldier(hp, c);
    }
    Soldier* createSoldier(Citizen* ent, int str){
        Soldier* person = new Soldier(*ent);
        person->setDamage(str);
        return person;
    }
};

#endif