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


	/** 
	* These functions instantiate new vehicle entities 	
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createLandVehicle()=0;
	virtual Vehicle* createAirVehicle()=0;
	virtual Vehicle* createSeaVehicle()=0;
	

	
	
	
};

#endif