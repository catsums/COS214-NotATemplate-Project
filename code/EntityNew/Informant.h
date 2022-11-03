#ifndef INFORMANT_H
#define INFORMANT_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Informant: public Citizen
{


public: 

	Informant();// default constuctor 
	Informant(int,string,int,int,int);// param constuctor 
	
	virtual ~Informant(); //destructor

	

	
	
	
};

#endif