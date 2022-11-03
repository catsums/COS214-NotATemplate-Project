#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Transport: public Vehicle
{
private:

	int feul;

public: 

	Transport();// default constuctor 
	Transport(int,string,int,int,int);// param constuctor 
	
	virtual ~Transport(); //destructor

	void setFeul(int);

	int getFeul();


	/*

	This function couts all the entity variables

	*/

	virtual void infoSummary();
	
	/*
	This function will decrease the feul of a vehicle
	it takes in a pointer to an Transport and an int amount to decrease the feul

	*/

	virtual void decreaseFeul(Transport*,int)=0;

	
	
	
};

#endif