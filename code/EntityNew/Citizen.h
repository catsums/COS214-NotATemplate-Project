/** @file Citizen.h
 *  @brief This is the header file to create citizens in our entity class.
 *
 *  When creating an entity we have have a different type of entity called a citizen who is just an ordinary person who
 *  resides in that country. 
 */



#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include "Entity.h"

using namespace std; 

class Citizen: public Entity
{


public: 
	/** Default constructor for citizen
    */
	Citizen();

	/** A parameter constructer that initializes 5 parameters 
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	Citizen(int,string,int,int,int); 
	

	/** Destructor 
    */
	virtual ~Citizen();

	

	/**	This function takes in an integer amount that will decrease 
	*	the entity's hp
	* 	@param int variable that takes certain amount of damage 
	*/
	virtual void takeDamage(int);
	

	/**	This function will deal a damage amount to another entity
	*	
	*/

	virtual int dealDamage();

	
	/** This function allow the entity to move
	*	@param int variable that takes x-coordinates 
	*	@param int variable that takes y-coordinates 
	*/

	virtual void move(int,int);


	/** This function will allow an entity to recieve more hp eg. From a medic
	*	@param int variable that take in health points (hp)
	*/

	virtual void recieveHp(int);

	/** This function will provide health to other entities.
	*	It returns an integer value that will be added to an entity's health
	*	Only implemented in Medic
	*/
	virtual int getHeal();

		
	
	
};

#endif