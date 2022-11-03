#ifndef FighterJet_H
#define FighterJet_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class FighterJet: public Artillery
{


public: 

	FighterJet();// default constuctor 
	FighterJet(int,string,int,int,int);// param constuctor 
	
	virtual ~FighterJet(); //destructor

	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif