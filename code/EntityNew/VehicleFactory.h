#ifndef VehicleFACTORY_H
#define VehicleFACTORY_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class VehicleFactory: public EntityFactory
{


public: 

	VehicleFactory();// default constuctor 
	
	
	virtual ~VehicleFactory(); //destructor

	virtual Vehicle* createVehicle()=0;
	

	
	
	
};

#endif