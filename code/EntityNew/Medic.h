#ifndef MEDIC_H
#define MEDIC_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Medic: public Citizen
{

private:

	int healAmount;


public: 

	Medic();// default constuctor 
	Medic(int,string,int,int,int);// param constuctor 
	
	virtual ~Medic(); //destructor

	//getters
	
	/*
	This function will provide health to other entities.
	It returns an integer value that will be added to an entity's health
	*/
	int getHeal();

	//setters

	void setHeal(int h);




	
	

	

	
	
	
};

#endif