#ifndef ALLOUTFORCE_H
#define ALLOUTFORCE_H

#include "ArmyForce.h"

class AllOutForce : public ArmyForce
{
private:
    /* data */

public:
    AllOutForce():ArmyForce("Default"){

    }
    ~AllOutForce(){

    }
    vector<Entity*> getActiveForce(vector<Entity*> ents){
        vector<Entity*> activeForce;
        for(int i=0;i<(int)ents.size(); i++){
            Entity* ent = ents[i];
            if(!ent) continue;

            activeForce.push_back(ent);
            
        }
        return activeForce;
    }
};

#endif
