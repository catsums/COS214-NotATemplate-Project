#ifndef SeaVehicle_H
#define SeaVehicle_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class SeaVehicle: public Vehicle{
public:
	SeaVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		type = "SeaVehicle";
		sea = true;
	}
	SeaVehicle(SeaVehicle& ent):Vehicle(ent){
		type = "SeaVehicle";
		sea = true;
	}
	~SeaVehicle(){

	}

	virtual Resource* clone(){
		return new SeaVehicle(*this);
	}

	///set/get

protected:

};

#endif