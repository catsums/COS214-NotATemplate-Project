/** @file Submarine.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef Submarine_H
#define Submarine_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class Submarine: public Artillery
{


public: 

	/** Default constructor for submarine
    */
	Submarine(); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from artillery class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	Submarine(int,string,int,int,int);// param constuctor 
	
	/** Destructor 
    */
	virtual ~Submarine(); 


	/** Function that decreases the fuel for the submarine
	*	this function takes in two parametres.
	*	@param first parameter takes in a artillery type 
	*	@param second parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(Artillery*,int);
	

	
	
	
};

#endif