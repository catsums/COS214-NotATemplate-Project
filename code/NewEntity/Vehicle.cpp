#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int hp, string c, string t, int f):Entity(hp,c,t):Resource(){
	fuel = f;
}
Vehicle::~Vehicle(){

}

bool Vehicle::travel(int x, int y){
	if(fuel>0){
		fuel--;
		setPosition(x,y);
		return true;
	}
	return false;
}
void attack(Entity* target){
	return;
}

#endif