/** @file Transport.h
 *  @brief This is the header file to create many types entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef TRANSPORT_H
#define TRANSPORT_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class Transport: public Vehicle
{
private:

	int feul; /**<int variable holding the amount of fuel*/

public: 

	/** Default constructor for transport
    */
	Transport();


	/** A parameter constructer taht initializes 5 parameters inherits the variables from vehicle class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	Transport(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~Transport(); 

	/** Function that sets the amount of fuel this transport
	*	vehicle is supposed ot have.
	*	@param takes in int value which represnts the amount of fuel in 
	*	transport vehicle
	*/
	void setFeul(int);

	/**Fucntion to retrieve the amount of fuel any given
	*	transport may have in that time.
	*/
	int getFeul();


	/**This function couts all the entity variables
	*/
	virtual void infoSummary();
	
	/**This function will decrease the feul of a vehicle
	*	it takes in a pointer to an Transport and an int amount to decrease the feul
	*	This is a pure virtual function. This means this function will 
	*	be used 
	*/
	virtual void decreaseFeul(Transport*,int)=0;

	
	
	
};

#endif