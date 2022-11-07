#ifndef AIRFORCE_H
#define AIRFORCE_H

#include "ArmyForce.h"

class AirForce:public ArmyForce
{
private:
    /* data */
public:
    AirForce():ArmyForce("AirForce"){

    }
    ~AirForce(){

    }
    vector<Entity*> getActiveForce(vector<Entity*> ents){
        vector<Entity*> activeForce;
        for(int i=0;i<(int)ents.size(); i++){
            Entity* ent = ents[i];
            if(!ent) continue;

            if(ent->canTravelSea() && ent->canTravelLand()){
                // cout<<"it air"<<endl;
                activeForce.push_back(ent);
            }
        }
        return activeForce;
    }
};

#endif

