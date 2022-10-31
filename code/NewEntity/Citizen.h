#ifndef CITZEN_H
#define CITIZEN_H

#include "Entity.h"

class Citizen : public Entity
{
private:
    /* data */
    string influence;
public:
    Citizen(/* args */);
    ~Citizen();
    bool takeDamage();
    void heal(int);
    void travel();
    virtual void attack(Entity&);
};

#endif
