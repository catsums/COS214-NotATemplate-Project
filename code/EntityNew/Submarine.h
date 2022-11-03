#ifndef Submarine_H
#define Submarine_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class Submarine: public Artillery
{


public: 

	Submarine();// default constuctor 
	Submarine(int,string,int,int,int);// param constuctor 
	
	virtual ~Submarine(); //destructor

	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif