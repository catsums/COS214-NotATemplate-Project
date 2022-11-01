#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class LandVehicle: public Vehicle{
public:
	LandVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		types.push_back("LandVehicle");
		land = true;
	}
	LandVehicle(LandVehicle& ent):Vehicle(ent){
		types.push_back("LandVehicle");
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