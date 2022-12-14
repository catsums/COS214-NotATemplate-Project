#ifndef MEDIC_H
#define MEDIC_H

#include "Citizen.h"

class Medic : public Citizen
{
private:
    /* data */
protected:
    int healingAmt = 2;

public:
    Medic(int hp) : Citizen(hp)
    {
        types.push_back("Medic");
        healingAmt = 2;
    }
    Medic(int hp, string c) : Citizen(hp, c)
    {
        types.push_back("Medic");
        healingAmt = 2;
    }
    Medic(int hp, string c, int healing) : Citizen(hp, c)
    {
        types.push_back("Medic");
        healingAmt = healing;
    }
    Medic(Citizen& ent):Citizen(ent){
        types.push_back("Medic");
    }
    Medic(Medic& ent):Citizen(ent){
        types.push_back("Medic");
        healingAmt = ent.healingAmt;
    }
    ~Medic();
    virtual void attack(Entity* target)
    {
        return;
    }
    virtual bool healPerson(Citizen* ent){
        if(ent->isAlive()){
            ent->heal(healingAmt);
            return true;
        }
        return false;
    }

    virtual void useKit(Citizen* target){
        item->useOn(target);
    }

    ///set/get
    void setHealingAmt(int amt){
        healingAmt = amt;
    }
    int getHealingAmt(){
        return healingAmt;
    }

    virtual string getInfo(){
        stringstream ss;

        string initInfo = Citizen::getInfo();

        ss << initInfo;
        ss << " HealingAmt: " << getHealingAmt() << "|";


        return ss.str();
    }
};

#endif
