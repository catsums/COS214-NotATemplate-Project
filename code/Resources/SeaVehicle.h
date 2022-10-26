#ifndef SEAVEHICLE_H
#define SEAVEHICLE_H

#include <string>


using namespace std; 

class SeaVehicle
{

private:

	int fuel;
	
	virtual void moveVehicle(int) = 0; // will decrease the fuel of a vehicle



public: 

	SeaVehicle();// default constuctor

	virtual ~SeaVehicle(); //destructor
	
	

	//getters
	int getFuel();


	//setters
	void setFuel(int);
};

#endif