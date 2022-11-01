#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Entity.h"
#include "../NewResource/Resource.h"

using namespace std;

class Vehicle: public Entity, public Resource{
public:
	Vehicle(int hp, string c, int f);
	Vehicle(Vehicle& ent);
	~Vehicle();

	virtual bool travel(int x, int y);
	virtual void attack(Entity* target);
	virtual Resource* clone();

	///set/get

	void setFuel(int f){
		fuel = f;
	}
	int getFuel(){
		return fuel;
	}
protected:
	int fuel;

};

#endif