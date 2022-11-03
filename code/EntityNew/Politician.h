#ifndef POLITICIAN_H
#define POLITICIAN_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Politician: public Citizen
{


public: 

	Politician();// default constuctor 
	Politician(int,string,int,int,int);// param constuctor 
	
	virtual ~Politician(); //destructor

	

	
	
	
};

#endif