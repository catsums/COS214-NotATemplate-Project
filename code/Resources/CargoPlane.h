#ifndef CARGOPLANE_H
#define CARGOPLANE_H

#include <string>
#include "AirVehicle.h"


using namespace std; 

class CargoPlane: public AirVehicle
{

private:

	
	



public: 

	CargoPlane();// default constuctor

	virtual ~CargoPlane(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif