#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "BattleVehicle.h"
#include "LandVehicle.h"

using namespace std;

class Tank: public BattleVehicle, public LandVehicle{
public:
	Tank(int hp, string c, int f):BattleVehicle(hp,c,f),LandVehicle(hp,c,f){
		type = "Tank";
		strength = 20;
		ammo = 50;
	}
	Tank(int hp, string c, int f, int dmg):BattleVehicle(hp,c,f,dmg),LandVehicle(hp,c,f){
		type = "Tank";
		ammo = 50;
	}
	Tank(Tank& ent):BattleVehicle(ent), LandVehicle(ent){
		type = "Tank";
	}
	~Tank(){

	}

	void attack(Entity* target){
		if(ammo>0){
			target->takeDamage(strength);
			ammo -= strength;
		}
	}

	virtual Resource* clone(){
		return new Tank(*this);
	}

	///set/get

protected:

};

#endif