#ifndef POLITICIAN_H
#define POLITICIAN_H

#include "Citizen.h"

class Politician : public Citizen
{
private:
    /* data */
public:
    Politician(int hp):Citizen(hp){
        types.push_back("Politician");
    }
    Politician(int hp, string c):Citizen(hp,c){
        types.push_back("Politician");
    }
    // Politician(int hp, string c, int str):Citizen(hp,c){
    //     type = "Politician";
    //     damage = str;
    // }
    Politician(Citizen& ent):Citizen(ent){
        types.push_back("Politician");
    }
    Politician(Politician& ent):Citizen(ent){
        types.push_back("Politician");

    }
    ~Politician(){

    }

    virtual string getInfo(){
        stringstream ss;

        string initInfo = Citizen::getInfo();

        ss << initInfo;
        // ss << " Influence: " << getInfluence();
        // ss << " HasItem: " << (item) ? "Y" : "N";


        return ss.str();
    }

    ///set/get
};

#endif
