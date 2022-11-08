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
	/** Copy constructor for transport
    */
	Transport(Vehicle& v);


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


	/**This function couts all the entity variables
	*/
	virtual void infoSummary();
	
	

	/** This function will allow you to clone a vehicle using itself as a prototype 
	*/
	virtual Vehicle* clone()=0;
	
	
};

#endif