#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Entity
{

private:

	//Citizen *myCitizen; // product 
	


public: 

	Entity();// default constuctor
	virtual ~Entity(); //destructor

	//void makeEntity()

	virtual Citizen* createEntity(int,string) =0;// factory method
	



		
	
	
};

#endif