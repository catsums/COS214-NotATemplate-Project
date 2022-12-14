#ifndef VEHICLE_CPP
#define VEHICLE_CPP

#include <cmath>
#include <cstdlib>

#include "Vehicle.h"

using namespace std;

Vehicle::Vehicle(int hp, int f):Entity(hp),Resource(){
	fuel = f;
	Entity::types.push_back("Vehicle");
	Resource::types.push_back("Vehicle");
}
Vehicle::Vehicle(int hp, string c, int f):Entity(hp,c),Resource(){
	fuel = f;
	Entity::types.push_back("Vehicle");
	Resource::types.push_back("Vehicle");
}
Vehicle::Vehicle(Vehicle& ent):Entity(ent){
	fuel = ent.fuel;
	Entity::types.push_back("Vehicle");
	Resource::types.push_back("Vehicle");
}
Vehicle::~Vehicle(){

}

bool Vehicle::travel(int x, int y){
	if(fuel>0){
		int consumption = ((abs(zone.x - x) + abs(zone.y - y))/2); //get average of differences in distance travelled
		setPosition(x,y);
		fuel -= consumption;
		return true;
	}
	return false;
}
void Vehicle::attack(Entity* target){
	return;
}

Resource* Vehicle::clone(){
	return new Vehicle(*this);
}

#endif