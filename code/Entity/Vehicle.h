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
private:

	int feul;

public: 

	/** Default constructor for vehicle
    */
	Vehicle();
	/** Copy constructor for vehicle
    */
	Vehicle(Vehicle& v);

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

	/** Function that sets the amount of fuel this vehivle
	*	vehicle is supposed ot have.
	*	@param takes in int value which represnts the amount of fuel in 
	*	transport vehicle
	*/
	void setFeul(int);

	/**Fucntion to retrieve the amount of fuel any given
	*	transport may have in that time.
	*/
	int getFeul();

	/**This function will decrease the feul of a vehicle
	*	it takes in an int amount to decrease the feul
	*	This is a pure virtual function. This means this function will 
	*	be used to decrease fuel based on the type of vehicle it is
	*/
	virtual void decreaseFeul(int)=0;


	/** This function will allow you to clone a vehicle using itself as a prototype 
	*/
	virtual Vehicle* clone() = 0;
	
	
};

#endif