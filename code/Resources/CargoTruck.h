#ifndef CARGOTRUCK_H
#define CARGOTRUCK_H

#include <string>
#include "LandVehicle.h"


using namespace std; 

class CargoTruck: public LandVehicle
{

private:

	
	



public: 

	CargoTruck();// default constuctor

	virtual ~CargoTruck(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif