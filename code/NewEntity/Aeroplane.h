#ifndef AEROPLAN_H
#define AEROPLAN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "TransportVehicle.h"
#include "AirVehicle.h"
#include "Citizen.h"

using namespace std;

class Aeroplane:public AirVehicle, public TransportVehicle{
	static const int SEATCAPACITY = 20;
	static const int CARGOCAPACITY = 10;
public:
	Aeroplane(int hp, string c, int f):Vehicle(hp,c,f),AirVehicle(hp,c,f),TransportVehicle(hp,c,f){
		types.push_back("Aeroplane");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	Aeroplane(Truck& ent):Vehicle(ent),AirVehicle(ent),TransportVehicle(ent){
		types.push_back("Aeroplane");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	~Aeroplane(){

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