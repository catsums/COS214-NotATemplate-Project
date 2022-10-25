#ifndef ARMYVEHICLE_H
#define ARMYVEHICLE_H

#include <string>


using namespace std; 

class ArmyVehicle : public Vehicle
{


public: 

	ArmyVehicle();// default constuctor

	virtual ~ArmyVehicle(); //destructor

	


	virtual LandVehicle* createLandVehicle(); 
	
	//virtual AirVehicle* createAirVehicle();	

	//virtual SeaVehicle* createSeaVehicle();	


	

	
	
};

#endif