#ifndef Transport_H
#define Transport_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Transport: public Vehicle
{


public: 

	Transport();// default constuctor 
	Transport(int,string,int,int,int);// param constuctor 
	
	virtual ~Transport(); //destructor

	

	
	
	
};

#endif