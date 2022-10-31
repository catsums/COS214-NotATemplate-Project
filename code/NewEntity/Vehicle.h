#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Entity.h"
#include "Resource.h"

using namespace std;

class Vehicle: public Entity, private Resource{
public:
	Vehicle(int hp, string c, string t, int f);
	~Vehicle();

	virtual bool travel(int x, int y);
	virtual void attack(Entity* target);
protected:
	int fuel;

private:
	virtual void useOn(Entity* ent){
		return;
	}
};

#endif