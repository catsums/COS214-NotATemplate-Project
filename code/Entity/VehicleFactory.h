/** @file VehicleFactory.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef VehicleFACTORY_H
#define VehicleFACTORY_H

#include <string>
#include "Vehicle.h"

using namespace std; 

class VehicleFactory: public EntityFactory
{


public: 

	/** Default constructor for vehicle factory
    */
	VehicleFactory(); 
	
	/** Destructor 
    */
	virtual ~VehicleFactory(); 


	/** This function instantiates new vehicle entities 
	*	based on the string paramter value passed in,
	* 	it will know whether to be a land,sea or air vehicle
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createVehicle(string)=0;
	

	
	
	
};

#endif