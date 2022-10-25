#ifndef TransportVEHICLE_H
#define TransportVEHICLE_H

#include <string>


using namespace std; 

class TransportVehicle : public Vehicle
{


public: 

	TransportVehicle();// default constuctor

	virtual ~TransportVehicle(); //destructor

	


	virtual LandVehicle* createLandVehicle(); 
	
	//virtual void createAirVehicle();	// TODO: Change return type

	//virtual void createSeaVehicle();	// TODO: Change return type


	

	
	
};

#endif