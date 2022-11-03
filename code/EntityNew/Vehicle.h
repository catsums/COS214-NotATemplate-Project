#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Entity.h"

using namespace std; 

class Vehicle: public Entity
{


public: 

	Vehicle();// default constuctor 
	Vehicle(int,string,int,int,int);// param constuctor 
	
	virtual ~Vehicle(); //destructor


	/*

	This function couts all the entity variables

	*/

	virtual void infoSummary();

	/*

	This function takes in an integer amount that will decrease 
	the entity's hp

	*/

	virtual void takeDamage(int);
	

	/*

	This function will deal a damage amount to another entity

	*/

	virtual int dealDamage();

	
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