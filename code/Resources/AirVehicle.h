#ifndef AIRVEHICLE_H
#define AIRVEHICLE_H

#include <string>


using namespace std; 

class AirVehicle
{

private:

	int fuel;
	
	virtual void moveVehicle(int) = 0; // will decrease the fuel of a vehicle



public: 

	AirVehicle();// default constuctor

	virtual ~AirVehicle(); //destructor
	
	

	//getters
	int getFuel();


	//setters
	void setFuel(int);
};

#endif