#ifndef CITZEN_H
#define CITIZEN_H

#include "Entity.h"

class Citizen : public Entity
{
private:
    /* data */
    string influence;
public:
    Citizen(int, string, string);
    ~Citizen();
    bool takeDamage();
    virtual void heal(int hp){
        this->HP += hp;
    }
	virtual bool travel(int x, int y){
        this->zone.x = x;
        this->zone.y = y;
    }
    virtual void attack(Entity&e){
        
    }
};

#endif
