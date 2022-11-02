#ifndef BATTLEVEHICLE_CPP
#define BATTLEVEHICLE_CPP

#include "BattleVehicle.h"

using namespace std;

BattleVehicle::BattleVehicle(int hp, string c, int f):Vehicle(hp,c,f){
	types.push_back("BattleVehicle");
	ammo = 100;
}
BattleVehicle::BattleVehicle(int hp, string c, int f, int dmg):Vehicle(hp,c,f){
	types.push_back("BattleVehicle");
	strength = dmg;
	ammo = 100;
}
BattleVehicle::BattleVehicle(BattleVehicle& ent):Vehicle(ent){
	types.push_back("BattleVehicle");
	strength = ent.strength;
	ammo = ent.ammo;
}
BattleVehicle::~BattleVehicle(){
	
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