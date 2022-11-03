#ifndef CARGOPLANE_H
#define CARGOPLANE_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class CargoPlane: public Transport
{


public: 

	CargoPlane();// default constuctor 
	CargoPlane(int,string,int,int,int);// param constuctor 
	
	virtual ~CargoPlane(); //destructor

	virtual void decreaseFeul(Transport*,int);
	

	
	
	
};

#endif