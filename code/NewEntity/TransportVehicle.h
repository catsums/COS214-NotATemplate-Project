#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class TransportVehicle: public virtual Vehicle{
public:
	TransportVehicle(int hp, string c, int f);
	TransportVehicle(TransportVehicle& ent);
	~TransportVehicle();

	virtual Resource* clone();

	virtual bool carryEntity(Entity* ent);
	virtual Entity* dropOff();
	virtual Entity* dropOff(Entity* ent);

	virtual bool travel(int x, int y);
	virtual void die();

	///set/get

	int getCapacity(){
		return capacity;
	}

	virtual int getStrength(){
		int str = 0;
		for(int i=0; i<(int)entities.size();i++){
			Entity* ent = entities[i];
			if(ent){
				str += ent->getStrength();
			}
		}
		return str;
	}

protected:
	vector<Entity*> entities;
	int capacity = 1;
};

#endif