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
	Truck(int hp, int f):Vehicle(hp,f),LandVehicle(hp,f),TransportVehicle(hp,f){
		Entity::types.push_back("Truck");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	Truck(int hp, string c, int f):Vehicle(hp,c,f),LandVehicle(hp,c,f),TransportVehicle(hp,c,f){
		Entity::types.push_back("Truck");
		entityCapacity = SEATCAPACITY;
		resourceCapacity = CARGOCAPACITY;
	}
	Truck(Truck& ent):Vehicle(ent),LandVehicle(ent),TransportVehicle(ent){
		Entity::types.push_back("Truck");
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

	virtual string getInfo(){
        stringstream ss;

        string initInfo = TransportVehicle::getInfo();

        ss << initInfo;
        // ss << " Ammo: " << getAmmo();
        // ss << " Damage: " << getDamage();


        return ss.str();
    }

	///set/get

protected:

};

#endif