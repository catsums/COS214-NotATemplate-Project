#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Entity.h"
#include "Resource.h"

using namespace std;

enum influence{
    LOW, MEDIUM, HIGH
};

class Citizen : public Entity
{
protected:
    /* data */
    string influence;
    Resource* item;
public:
    Citizen(int hp, string c):Entity(hp,c){
        type = "Citizen";
        influence = "medium";
        item = NULL;
    }
    Citizen(Citizen& ent):Entity(ent){
        type = "Citizen";
        influence = ent.influence;
        if(ent.item){
            item = ent.item->clone();
        }
    }
    ~Citizen(){
        item = NULL;
    }
    virtual bool takeDamage(int dmg){
        this->HP -= dmg;
        if(HP<=0){
            HP = 0;
            return true;
        }
        return false;
    }
    virtual void heal(int hp){
        if(this->isAlive()){
            this->HP += hp;
        }
    }
	virtual bool travel(int x, int y){
        this->zone.x = x;
        this->zone.y = y;
        return true;
    }
    virtual void attack(Entity* e){
        return;
    }

    virtual Resource* equipItem(Resource* _item){
        Resource* temp = item;
        item = _item;
        return temp;
    }
    virtual Resource* unequipItem(){
        Resource* temp = item;
        item = NULL;
        return temp;
    }

    virtual void useItem(Entity* ent){
        if(item){
            item->useOn(ent);
        }
    }

    /////set/get
    Resource* getItem(){
        return item;
    }
    string getInfluence(){
        return influence;
    }
    void setInfluence(string inf){
        influence = inf;
    }
};

#endif
