#ifndef TRUCK_H
#define TRUCK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "TransportVehicle.h"
#include "LandVehicle.h"
#include "Citizen.h"

using namespace std;

class Truck:public LandVehicle, public TransportVehicle{
public:
	Truck(int hp, string c, int f):Vehicle(hp,c,f),LandVehicle(hp,c,f),TransportVehicle(hp,c,f){
		types.push_back("Truck");
		capacity = 6;
	}
	Truck(Truck& ent):Vehicle(ent),LandVehicle(ent),TransportVehicle(ent){
		types.push_back("Truck");
		capacity = 6;
	}
	~Truck(){

	}

	bool carryPassenger(Citizen* ctn){
		return carryEntity(ctn);
	}
	Citizen* dropOffPassenger(){
		try{
			Entity* ent = dropOff();
			if(ent){
				Citizen* ctn = static_cast<Citizen*>(ent);
				return ctn;
			}
			
		}catch(const exception& err){
			
		}
		return NULL;
	}
	Citizen* dropOffPassenger(Citizen* _ent){
		try{
			Entity* ent = dropOff(_ent);
			if(ent){
				Citizen* ctn = static_cast<Citizen*>(ent);
				return ctn;
			}
		}catch(const exception& err){
			
		}
		return NULL;
	}

	virtual Resource* clone(){
		return new Truck(*this);
	}

	///set/get

protected:

};

#endif