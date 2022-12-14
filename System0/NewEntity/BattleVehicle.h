#ifndef BATTLEVEHICLE_H
#define BATTLEVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class BattleVehicle: public virtual Vehicle{
public:
	BattleVehicle(int hp, int f);
	BattleVehicle(int hp, string c, int f);
	BattleVehicle(int hp, string c, int f, int dmg);
	BattleVehicle(BattleVehicle& ent);
	~BattleVehicle();

	virtual Resource* clone();

	virtual bool travel(int x, int y);

	virtual void attack(Entity* target);

	///set/get

	void setAmmo(int amm){
		ammo = amm;
	}
	int getAmmo(){
		return ammo;
	}

	void setDamage(int str){
		strength = str;
	}
	int getDamage(){
		return strength;
	}

	virtual int getOverallStrength(){
        return HP + strength;
    }

    virtual string getInfo(){
        stringstream ss;

        string initInfo = Vehicle::getInfo();

        ss << initInfo;
        ss << " Ammo: " << getAmmo() << "|";
        ss << " Damage: " << getDamage() << "|";


        return ss.str();
    }

protected:
	int strength = 5;
	int ammo = 100;
};

#endif