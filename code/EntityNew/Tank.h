#ifndef TANK_H
#define TANK_H

#include <string>
#include "Artillery.h"


using namespace std; 

class Tank: public Artillery
{

	
	



public: 

	Tank();// default constuctor

	virtual ~Tank(); //destructor
	
	virtual void decreaseFeul(Artillery*,int);
	
	
};

#endif