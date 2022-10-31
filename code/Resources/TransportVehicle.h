#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <string>


using namespace std; 

class TransportVehicle : public Vehicle
{


public: 

	TransportVehicle();// default constuctor

	virtual ~TransportVehicle(); //destructor

	


	virtual LandVehicle* createLandVehicle(); 
	
	virtual AirVehicle* createAirVehicle();	// TODO: Change return type

	virtual SeaVehicle* createSeaVehicle();	// TODO: Change return type


	

	
	
};

#endif