#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>



using namespace std; 

class EntityFactory: 
{


public: 

	EntityFactory();// default constuctor 
	 
	
	virtual ~EntityFactory(); //destructor

	
	virtual Citizen* createCitizen() =0;
	virtual Vehicle* createVehicle() =0;

	
	
	
};

#endif