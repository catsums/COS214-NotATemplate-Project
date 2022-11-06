#ifndef ARMYFORCE_H
#define ARMYFORCE_H

#include <iostream>
#include <vector>
#include <string>
#include "../NewEntity/Entity.h"
#include "../myHelper.cpp"

using namespace std;

class ArmyForce
{
private:
    vector<Entity*> entities;
public:
    ArmyForce(){

    }
    ArmyForce(vector<Entity*> army){
        entities = army;
    }
    ~ArmyForce(){
        
    }

    virtual void addEntity(Entity* ent){
        entities.push_back(ent);
    }

    Entity* getRandomEntity(){
        if(entities.size()>0){
            int index = myHelper::getRandomInt(0, entities.size());

            return entities[index];
        }
        return NULL;
    }

    virtual bool attack(ArmyForce* targetForce){
        bool gotHit = false;
        if(targetForce){
            for(int i=0; i<(int)entities.size(); i++){
                Entity* currentEnt = entities[i];
                if(currentEnt){
                    Entity* target = targetForce->getRandomEntity();
                    if(target){
                        currentEnt->attack(target);
                        gotHit = true;
                    }
                }
            }
        }
        return gotHit;
    }

};

#endif

