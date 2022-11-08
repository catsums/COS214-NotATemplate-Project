#ifndef NAVALFORCE_H
#define NAVALFORCE_H

#include "ArmyForce.h"

class NavalForce : public ArmyForce
{
public:
    NavalForce():ArmyForce("NavalForce"){
        
    }
    ~NavalForce(){

    }
    vector<Entity*> getActiveForce(vector<Entity*> ents){
        vector<Entity*> activeForce;
        for(int i=0;i<(int)ents.size(); i++){
            Entity* ent = ents[i];
            if(!ent) continue;

            if(ent->canTravelSea() && !ent->canTravelLand()){
                activeForce.push_back(ent);
            }
        }
        return activeForce;
    }
};

#endif
