/** @file CargoPlane.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef CARGOPLANE_H
#define CARGOPLANE_H

#include <string>
#include "Vehicle.h"
#include "Transport.h"

using namespace std; 

class CargoPlane: public Transport
{


public: 

	/** Default constructor for CargoPlane
    */
	CargoPlane(); 
	/** Copy constructor for CargoPlane
    */
	CargoPlane(Transport& v); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from transport class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	CargoPlane(int,string,int,int,int); 
	

	/** Destructor 
    */
	virtual ~CargoPlane(); 


	/** Function that decreases the fuel for the cargo plane
	*	@param int parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(int);
	

	virtual Vehicle* clone();
	
};

#endif