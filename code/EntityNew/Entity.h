#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Entity
{

private:

	int hp; // health of each entity 
	string country // country each entity belongs to 
	// TODO: change to country type



public: 

	Entity();// default constuctor
	virtual ~Entity(); //destructor

	
	void setHp(int);

	void setCountry(string);
	


	int getHp();

	string getCountry();
	

	
	



		
	
	
};

#endif