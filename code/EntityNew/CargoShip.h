#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class CargoShip: public Transport
{


public: 

	CargoShip();// default constuctor 
	CargoShip(int,string,int,int,int);// param constuctor 
	
	virtual ~CargoShip(); //destructor

	virtual void decreaseFeul(Transport*,int);
	

	
	
	
};

#endif