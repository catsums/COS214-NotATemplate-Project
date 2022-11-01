#ifndef CITIZEN_H
#define CITIZEN_H

#include <iostream>
#include <iomanip>
#include <string>

#include "../Structs.h"
#include "Entity.h"
#include "../NewResource/Item.h"

using namespace std;

class Citizen : public Entity
{
protected:
    /* data */
    string influence;
    Item* item;
public:
    Citizen(int hp, string c):Entity(hp,c){
        types.push_back("Citizen");
        influence = "medium";
        item = NULL;

        land = true;
        sea = false;
    }
    Citizen(Citizen& ent):Entity(ent){
        types.push_back("Citizen");
        influence = ent.influence;
        if(ent.item){
            item = ent.item->clone();
        }

        land = true;
        sea = false;
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

    virtual Item* equipItem(Item* _item){
        Item* temp = item;
        item = _item;
        return temp;
    }
    virtual Resource* unequipItem(){
        Item* temp = item;
        item = NULL;
        return temp;
    }

    virtual void useItem(Entity* ent){
        if(item){
            item->useOn(ent);
        }
    }

    /////set/get
    Item* getItem(){
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
