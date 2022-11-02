#ifndef MEDIC_H
#define MEDIC_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Medic : public Citizen
{

protected:


public: 

	Medic();// default constuctor 
	Medic(int,string,string);// param constuctor 
	
	virtual ~Medic(); //destructor


		
	
	
};

#endif