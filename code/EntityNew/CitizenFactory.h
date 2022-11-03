#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class CitizenFactory: public EntityFactory
{


public: 

	CitizenFactory();// default constuctor 
	
	
	virtual ~CitizenFactory(); //destructor

	virtual Citizen* createCitizen()=0;
	

	
	
	
};

#endif