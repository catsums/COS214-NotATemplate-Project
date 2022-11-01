#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class TransportVehicle: public Vehicle{
public:
	TransportVehicle(int hp, string c, int f);
	TransportVehicle(TransportVehicle& ent);
	~TransportVehicle();

	virtual Resource* clone();

	virtual bool carryEntity(Entity* ent);
	virtual Entity* dropOff();
	virtual Entity* dropOff(Entity* ent);

	virtual bool travel(int x, int y);

	///set/get

	int getCapacity(){
		return capacity;
	}

protected:
	vector<Entity*> entities;
	int capacity = 1;
};

#endif