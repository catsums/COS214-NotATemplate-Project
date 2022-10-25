#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>


using namespace std; 

class Vehicle
{




public: 

	Vehicle();// default constuctor

	virtual ~Vehicle(); //destructor

	


	virtual void createLandVehicle() =0; // TODO: Change return type 
	
	virtual void createAirVehicle() =0;	// TODO: Change return type

	virtual void createSeaVehicle() =0;	// TODO: Change return type


	

	
	
};

#endif