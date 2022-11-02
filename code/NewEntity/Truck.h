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
	static const int SEATCAPACITY = 6;
	static const int CARGOCAPACITY = 2;
public:
	Truck(int hp, string c, int f):Vehicle(hp,c,f),LandVehicle(hp,c,f),TransportVehicle(hp,c,f){
		types.push_back("Truck");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	Truck(Truck& ent):Vehicle(ent),LandVehicle(ent),TransportVehicle(ent){
		types.push_back("Truck");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	~Truck(){

	}

	bool carryPassenger(Citizen* ctn){
		return carryEntity(ctn);
	}
	Citizen* dropOffPassenger(){
		try{
			Entity* ent = dropOffEntity();
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
			Entity* ent = dropOffEntity(_ent);
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