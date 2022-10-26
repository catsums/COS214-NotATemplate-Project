#ifndef SUBMARINE_H
#define SUBMARINE_H

#include <string>
#include "SeaVehicle.h"


using namespace std; 

class Submarine: public SeaVehicle
{

private:

	
	



public: 

	Submarine();// default constuctor

	virtual ~Submarine(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif