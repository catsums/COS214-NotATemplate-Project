#ifndef ARTILLERY_H
#define ARTILLERY_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Artillery: public Vehicle
{
private:

	int feul;

public: 

	Artillery();// default constuctor 
	Artillery(int,string,int,int,int);// param constuctor 
	
	virtual ~Artillery(); //destructor

	void setFeul(int);

	int getFeul();


	/*
	This function will decrease the feul of a vehicle
	it takes in a pointer to an artillery and an int amount to decrease the feul

	*/

	virtual void decreaseFeul(Artillery*,int)=0;

	
	
	
};

#endif