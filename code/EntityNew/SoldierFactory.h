#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class SoldierFactory: public CitizenFactory
{

protected:

	Citizen * myCitizen;

public: 

	SoldierFactory();// default constuctor 
	SoldierFactory(int,string,int,int,int);// param constuctor 
	
	virtual ~SoldierFactory(); //destructor

	/*
	
	*/
	
	virtual Citizen* createCitizen();
	
	
	
};

#endif