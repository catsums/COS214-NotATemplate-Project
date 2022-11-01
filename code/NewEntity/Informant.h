#ifndef INFORMANT_H
#define INFORMANT_H

#include "Citizen.h"

class Informant : public Citizen
{
protected:
    /* data */
public:
    Informant(int hp, string c) : Citizen(hp, c)
    {
        type = "Informant";
    }
    // Informant(int hp, string c) : Citizen(hp, c)
    // {
    //     type = "Informant";
    // }
    Informant(Citizen& ent):Citizen(ent){
        type = "Informant";
    }
    Informant(Informant& ent):Citizen(ent){
        type = "Informant";
        //maybe something unique to informat
    }
    ~Informant();
    virtual void attack(Entity* target)
    {
        return;
    }
    void sendIntel(string request){
        return;
    }

    ///set/get
};

#endif
