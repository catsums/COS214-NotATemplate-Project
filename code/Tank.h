#ifndef TANK_H
#define TANK_H

#include <string>
#include "LandVehicle.h"


using namespace std; 

class Tank
{

private:

	int fuel;
	



public: 

	Tank();// default constuctor

	virtual ~Tank(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif