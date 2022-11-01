#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class AirVehicle: public Vehicle{
public:
	AirVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		types.push_back("AirVehicle");
		land = true;
		sea = true;
	}
	AirVehicle(AirVehicle& ent):Vehicle(ent){
		types.push_back("AirVehicle");
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