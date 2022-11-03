#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class AirVehicle: public virtual Vehicle{
public:
	AirVehicle(int hp, int f):Vehicle(hp,f){
		Entity::types.push_back("AirVehicle");
		land = true;
		sea = true;
	}
	AirVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		Entity::types.push_back("AirVehicle");
		land = true;
		sea = true;
	}
	AirVehicle(AirVehicle& ent):Vehicle(ent){
		Entity::types.push_back("AirVehicle");
		land = true;
		sea = true;
	}
	~AirVehicle(){

	}

	virtual Resource* clone(){
		return new AirVehicle(*this);
	}

	///set/get

protected:

};

#endif