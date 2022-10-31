#ifndef MEDIC_H
#define MEDIC_H

#include "Citizen.h"

class Medic : public Citizen
{
private:
    /* data */
public:
    Medic(int hp, string c, string m) : Citizen(hp, c, m)
    {
        type = "Medic";
    }
    Medic(Citizen& ent){
        HP = ent.HP;
        alive = ent.alive;
        country = ent.country;
        type = "Medic";
        zone = ent.zone;
    }
    ~Medic();
    virtual void attack(Entity* target)
    {
        return;
    }
};

#endif
