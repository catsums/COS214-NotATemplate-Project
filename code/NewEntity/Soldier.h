#ifndef SOLDIER_H
#define SOLDIER_H

#include "Citizen.h"

class Soldier : public Citizen
{
protected:
    /* data */
    int damage = 2;
public:
    Soldier(int hp, string c):Citizen(hp,c){
        types.push_back("Soldier");
    }
    Soldier(int hp, string c, int str):Citizen(hp,c){
        types.push_back("Soldier");
        damage = str;
    }
    Soldier(Citizen& ent):Citizen(ent){
        types.push_back("Soldier");
    }
    Soldier(Soldier& ent):Citizen(ent){
        types.push_back("Soldier");
        damage = ent.damage;
    }
    ~Soldier(){

    }
    virtual void attack(Entity* target)
    {
        target->takeDamage(damage);
    }

    virtual void useWeapon(Entity* target){
        item->useOn(target);
    }

    ///set/get
    void setDamage(int dmg){
        damage = dmg;
    }
    int getDamage(){
        return damage;
    }

    virtual int getOverallStrength(){
        return HP + damage;
    }

};

#endif
