#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class CitizenFactory: public EntityFactory
{


public: 

	CitizenFactory();// default constuctor 
	CitizenFactory(int,string,int,int,int);// param constuctor 
	
	virtual ~CitizenFactory(); //destructor

	

	
	
	
};

#endif