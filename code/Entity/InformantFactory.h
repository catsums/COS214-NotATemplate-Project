#ifndef INFORMANTFACTORY_H
#define INFORMANTFACTORY_H

#include <string>
#include "Citizen.h"
#include "Entity.h"
#include "Informant.h"


using namespace std; 

class InformantFactory: public Entity
{


public: 

	InformantFactory();// default constuctor
	virtual ~InformantFactory(); //destructor

	virtual Citizen* createEntity(int,string);// factory method
	



		
	
	
};

#endif