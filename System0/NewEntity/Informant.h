#ifndef INFORMANT_H
#define INFORMANT_H

#include "Citizen.h"

class Informant : public Citizen
{
protected:
    /* data */
public:
    Informant(int hp) : Citizen(hp)
    {
        types.push_back("Informant");
    }
    Informant(int hp, string c) : Citizen(hp, c)
    {
        types.push_back("Informant");
    }
    // Informant(int hp, string c) : Citizen(hp, c)
    // {
    //     types.push_back("Informant");
    // }
    Informant(Citizen& ent):Citizen(ent){
        types.push_back("Informant");
    }
    Informant(Informant& ent):Citizen(ent){
        types.push_back("Informant");
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
