/** @file CargoTruck.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef CARGOTRUCK_H
#define CARGOTRUCK_H

#include <string>
#include "Vehicle.h"
#include "Transport.h"

using namespace std; 

class CargoTruck: public Transport
{


public: 

	/** Default constructor for cargo truck
    */
	CargoTruck();
	/** Copy constructor for cargo truck
    */
	CargoTruck(Transport& v);

	/** A parameter constructer taht initializes 5 parameters inherits the variables from transport class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	CargoTruck(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~CargoTruck(); 

	/** Function that decreases the fuel for the cargo truck
	*	@param int parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(int);
	

	virtual Vehicle* clone();
	
	
};

#endif