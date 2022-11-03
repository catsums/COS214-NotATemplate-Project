#ifndef Tank_H
#define Tank_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class Tank: public Artillery
{


public: 

	Tank();// default constuctor 
	Tank(int,string,int,int,int);// param constuctor 
	
	virtual ~Tank(); //destructor

	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif