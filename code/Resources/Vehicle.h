#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "LandVehicle.h"
#include "AirVehicle.h"
#include "SeaVehicle.h"


using namespace std; 

class Vehicle
{




public: 

	Vehicle();// default constuctor

	virtual ~Vehicle(); //destructor

	


	virtual LandVehicle* createLandVehicle() =0; // TODO: Change return type 
	
	virtual AirVehicle* createAirVehicle() =0;	// TODO: Change return type

	virtual SeaVehicle*  createSeaVehicle() =0;	// TODO: Change return type


	

	
	
};

#endif