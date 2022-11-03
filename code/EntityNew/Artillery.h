#ifndef ARTILLERY_H
#define ARTILLERY_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Artillery: public Vehicle
{


public: 

	Artillery();// default constuctor 
	Artillery(int,string,int,int,int);// param constuctor 
	
	virtual ~Artillery(); //destructor

	

	
	
	
};

#endif