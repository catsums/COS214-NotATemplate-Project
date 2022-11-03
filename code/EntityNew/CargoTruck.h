#ifndef CARGOTRUCK_H
#define CARGOTRUCK_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class CargoTruck: public Transport
{


public: 

	CargoTruck();// default constuctor 
	CargoTruck(int,string,int,int,int);// param constuctor 
	
	virtual ~CargoTruck(); //destructor

	virtual void decreaseFeul(Transport*,int);
	

	
	
	
};

#endif