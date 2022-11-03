#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>
#include "Citizen.h"
#include "Vehicle.h"


using namespace std; 

class EntityFactory
{

public: 

	EntityFactory();// default constuctor 
	 
	
	virtual ~EntityFactory(); //destructor

	/*
	This function instantiates new citizen entities 
	and returns a refernce to it
	*/
	virtual Citizen* createCitizen();

	/*
	This function instantiates new vehicle entities 
	and returns a refernce to it
	*/
	virtual Vehicle* createVehicle();

	
	
	
};

#endif