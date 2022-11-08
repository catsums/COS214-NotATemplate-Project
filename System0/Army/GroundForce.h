#ifndef GROUNDFORCE_H
#define GROUNDFORCE_H

#include "ArmyForce.h"

class GroundForce : public ArmyForce
{
private:
    /* data */

public:
    GroundForce():ArmyForce("GroundForce"){

    }
    ~GroundForce(){

    }
    vector<Entity*> getActiveForce(vector<Entity*> ents){
        vector<Entity*> activeForce;
        for(int i=0;i<(int)ents.size(); i++){
            Entity* ent = ents[i];
            if(!ent) continue;

            if(!ent->canTravelSea() && ent->canTravelLand()){
                activeForce.push_back(ent);
            }
        }
        return activeForce;
    }
};

#endif
