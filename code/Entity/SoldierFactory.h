#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include <string>
#include "Citizen.h"
#include "Entity.h"
#include "Soldier.h"


using namespace std; 

class SoldierFactory: public Entity
{


public: 

	SoldierFactory();// default constuctor
	virtual ~SoldierFactory(); //destructor

	virtual Citizen* createEntity(int,string);// factory method
	



		
	
	
};

#endif