#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include "SeaVehicle.h"


using namespace std; 

class CargoShip: public SeaVehicle
{

private:

	
	



public: 

	CargoShip();// default constuctor

	virtual ~CargoShip(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif