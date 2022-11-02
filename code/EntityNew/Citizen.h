#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "Entity.h"

using namespace std; 

class Citizen: public Entity
{


public: 

	Citizen();// default constuctor 
	Citizen(int,string,int,int,int);// param constuctor 
	
	virtual ~Citizen(); //destructor

	

	/*

	This function takes in an integer amount that will decrease 
	the entity's hp

	*/

	virtual void takeDamage(int);
	

	/*

	This function will deal a damage amount to another entity

	*/

	virtual void dealDamage();

	
	/*

	This function allow the entity to move

	*/

	virtual void move(int,int);


	/*

	This function will allow an entity to recieve more hp 
	eg. From a medic

	*/

	virtual void recieveHp(int);



		
	
	
};

#endif