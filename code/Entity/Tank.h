/** @file Tank.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef TANK_H
#define TANK_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class Tank: public Artillery
{


public: 

	/** Default constructor for tank
    */
	Tank();

	/** A parameter constructer taht initializes 5 parameters inherits the variables from artillery class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */ 
	Tank(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~Tank(); 

	/** Function that decreases the fuel for the tank
	*	this function takes in two parametres.
	*	@param first parameter takes in a artillery type 
	*	@param second parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif