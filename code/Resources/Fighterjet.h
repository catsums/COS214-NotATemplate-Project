#ifndef FIGHTERJET_H
#define FIGHTERJET_H

#include <string>
#include "AirVehicle.h"


using namespace std; 

class Fighterjet: public AirVehicle
{

private:

	
	



public: 

	Fighterjet();// default constuctor

	virtual ~Fighterjet(); //destructor
	
	virtual void moveVehicle(int); // will decrease the fuel of a vehicle

	
};

#endif