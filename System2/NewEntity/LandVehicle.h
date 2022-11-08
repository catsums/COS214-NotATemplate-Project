#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class LandVehicle: public virtual Vehicle{
public:
	LandVehicle(int hp, int f):Vehicle(hp,f){
		Entity::types.push_back("LandVehicle");
		Resource::types.push_back("LandVehicle");
		land = true;
	}
	LandVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		Entity::types.push_back("LandVehicle");
		Resource::types.push_back("LandVehicle");
		land = true;
	}
	LandVehicle(LandVehicle& ent):Vehicle(ent){
		Entity::types.push_back("LandVehicle");
		Resource::types.push_back("LandVehicle");
		land = true;
	}
	~LandVehicle(){

	}

	virtual Resource* clone(){
		return new LandVehicle(*this);
	}

	///set/get

protected:

};

#endif