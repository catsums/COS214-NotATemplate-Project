#ifndef POLITICIAN_H
#define POLITICIAN_H

#include "Citizen.h"

class Politician : public Citizen
{
private:
    /* data */
public:
    Politician(int hp, string c):Citizen(hp,c){
        type = "Politician";
    }
    // Politician(int hp, string c, int str):Citizen(hp,c){
    //     type = "Politician";
    //     damage = str;
    // }
    Politician(Citizen& ent):Citizen(ent){
        type = "Politician";
    }
    Politician(Politician& ent):Citizen(ent){
        type = "Politician";

    }
    ~Politician(){

    }

    ///set/get
};

#endif
