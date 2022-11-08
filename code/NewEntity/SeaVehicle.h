#ifndef SeaVehicle_H
#define SeaVehicle_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class SeaVehicle: public virtual Vehicle{
public:
	SeaVehicle(int hp, int f):Vehicle(hp,f){
		Entity::types.push_back("SeaVehicle");
		sea = true;
	}
	SeaVehicle(int hp, string c, int f):Vehicle(hp,c,f){
		Entity::types.push_back("SeaVehicle");
		sea = true;
	}
	SeaVehicle(SeaVehicle& ent):Vehicle(ent){
		Entity::types.push_back("SeaVehicle");
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