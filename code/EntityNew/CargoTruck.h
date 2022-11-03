#ifndef CARGOTRUCK_H
#define CARGOTRUCK_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class CargoTruck: public Artillery
{


public: 

	CargoTruck();// default constuctor 
	CargoTruck(int,string,int,int,int);// param constuctor 
	
	virtual ~CargoTruck(); //destructor

	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif