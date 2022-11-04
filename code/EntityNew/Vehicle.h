/** @file Vehicle.h
 *  @brief This is the header file to create many types entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include "Entity.h"

using namespace std; 

class Vehicle: public Entity
{


public: 

	/** Default constructor for vehicle
    */
	Vehicle();

	/** A parameter constructer taht initializes 5 parameters inherits the variables from entity class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */ 
	Vehicle(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~Vehicle(); 


	/**This function couts all the entity variables
	*/
	virtual void infoSummary();

	/** This function takes in an integer amount that will decrease 
	*	the entity's hp
	*	@param int value that hold the number that will be decreased 
	*	from entities hp.
	*/
	virtual void takeDamage(int);
	

	/**This function will deal a damage amount to another entity
	*/
	virtual int dealDamage();

	
	/** This function allow the entity to move
	*	@param int value holding the x-position
	*	@param int value holding the y-position	
	*/

	virtual void move(int,int);


	/** This function will allow an entity to recieve more hp 
	*	eg. From a medic
	*	@param int value of the amount og health points can be
	*	given to an entity.
	*/
	virtual void recieveHp(int);



		
	
	
};

#endif