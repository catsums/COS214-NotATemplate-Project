#ifndef TANK_H
#define TANK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "BattleVehicle.h"
#include "LandVehicle.h"

using namespace std;

class Tank: public LandVehicle, public BattleVehicle{
public:
	Tank(int hp, string c, int f):Vehicle(hp,c,f),LandVehicle(hp,c,f),BattleVehicle(hp,c,f){
		types.push_back("Tank");
		strength = 20;
		ammo = 50;
	}
	Tank(int hp, string c, int f, int dmg):Vehicle(hp,c,f),LandVehicle(hp,c,f),BattleVehicle(hp,c,f,dmg){
		types.push_back("Tank");
		ammo = 50;
	}
	Tank(Tank& ent):Vehicle(ent),LandVehicle(ent),BattleVehicle(ent){
		types.push_back("Tank");
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

};

#endif