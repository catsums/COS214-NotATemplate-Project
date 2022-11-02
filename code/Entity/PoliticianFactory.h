#ifndef POLITICIANFACTORY_H
#define POLITICIANFACTORY_H

#include <string>
#include "Citizen.h"
#include "Entity.h"
#include "Politician.h"


using namespace std; 

class PoliticianFactory: public Entity
{


public: 

	PoliticianFactory();// default constuctor
	virtual ~PoliticianFactory(); //destructor

	virtual Citizen* createEntity(int,string);// factory method
	



		
	
	
};

#endif