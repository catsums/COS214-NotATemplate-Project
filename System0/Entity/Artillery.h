#ifndef ARTILLERY_H
#define ARTILLERY_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Artillery: public Vehicle
{

public: 

	Artillery();// default constuctor 
	Artillery(Vehicle& v);// copy constuctor 
	Artillery(int,string,int,int,int);// param constuctor 
	
	virtual ~Artillery(); //destructor


	/*

	This function couts all the entity variables

	*/

	virtual void infoSummary();

	/*

	This function lets you create a new Artillery based on this prototype

	*/
	
	virtual Vehicle* clone() = 0;
	
};

#endif