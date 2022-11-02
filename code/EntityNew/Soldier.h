#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Soldier: public Citizen
{


public: 

	Soldier();// default constuctor 
	Soldier(int,string,int,int,int);// param constuctor 
	
	virtual ~Soldier(); //destructor

	

	
	
	
};

#endif