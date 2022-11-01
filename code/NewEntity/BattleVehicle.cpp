#ifndef BATTLEVEHICLE_CPP
#define BATTLEVEHICLE_CPP

#include "BattleVehicle.h"

using namespace std;

BattleVehicle::BattleVehicle(int hp, string c, int f):Vehicle(hp,c,f){
	type = "BattleVehicle";
	ammo = 100;
}
BattleVehicle::BattleVehicle(int hp, string c, int f, int dmg):Vehicle(hp,c,f){
	type = "BattleVehicle";
	strength = dmg;
	ammo = 100;
}
BattleVehicle::BattleVehicle(BattleVehicle& ent):Vehicle(ent){
	type = "BattleVehicle";
	strength = ent.strength;
	ammo = ent.ammo;
}

void BattleVehicle::attack(Entity* target){
	if(ammo>0){
		target->takeDamage(strength);
		ammo -= 1;
	}
}

Resource* BattleVehicle::clone(){
	return new BattleVehicle(*this);
}

bool BattleVehicle::travel(int x, int y){
	bool canTravel = Vehicle::travel(x,y);

	return canTravel;
}

#endif