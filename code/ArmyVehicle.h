#ifndef ARMYVEHICLE_H
#define ARMYVEHICLE_H

#include <string>


using namespace std; 

class ArmyVehicle
{


public: 

	ArmyVehicle();// default constuctor

	virtual ~ArmyVehicle(); //destructor

	


	virtual void createLandVehicle(); // TODO: Change return type 
	
	virtual void createAirVehicle();	// TODO: Change return type

	virtual void createSeaVehicle();	// TODO: Change return type


	

	
	
};

#endif