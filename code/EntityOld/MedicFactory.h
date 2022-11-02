#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include <string>
#include "Citizen.h"
#include "Entity.h"
#include "Medic.h"


using namespace std; 

class MedicFactory: public Entity
{


public: 

	MedicFactory();// default constuctor
	virtual ~MedicFactory(); //destructor

	virtual Citizen* createEntity(int,string);// factory method
	



		
	
	
};

#endif