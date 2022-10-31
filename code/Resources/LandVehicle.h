#ifndef LANDVEHICLE_H
#define LANDVEHICLE_H

#include <string>


using namespace std; 

class LandVehicle
{

private:

	int fuel;
	
	virtual void moveVehicle(int) = 0; // will decrease the fuel of a vehicle



public: 

	LandVehicle();// default constuctor

	virtual ~LandVehicle(); //destructor
	
	

	//getters
	int getFuel();


	//setters
	void setFuel(int);
};

#endif