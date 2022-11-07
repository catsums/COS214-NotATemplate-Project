/** @file CargoShip.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef CARGOSHIP_H
#define CARGOSHIP_H

#include <string>
#include "Vehicle.h"
#include "Transport.h"

using namespace std; 

class CargoShip: public Transport
{


public: 

	/** Default constructor for artillery
    */
	CargoShip();
/** Copy constructor for artillery
    */
	CargoShip(Transport& v);

	/** A parameter constructer taht initializes 5 parameters inherits the variables from transport class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	CargoShip(int,string,int,int,int);
	

	/** Destructor 
    */
	virtual ~CargoShip(); 

	/** Function that decreases the fuel for the cargo ship 
	*	@param int parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(int);
	

	virtual Vehicle* clone();
	
	
};

#endif