/** @file ArtilleryFactory.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef ArtilleryFACTORY_H
#define ArtilleryFACTORY_H

#include <string>
#include "Vehicle.h"


using namespace std; 

class ArtilleryFactory:public VehicleFactory
{
protected:

	Vehicle * myVehicle;

public: 

	/** Default constructor for citizen
    */
	ArtilleryFactory(); 
	 
	/** Destructor 
    */
	virtual ~ArtilleryFactory(); 

	/** This function instantiates new vehicle entities 
	*	based on the string paramter value passed in,
	* 	it will know whether to be a land,sea or air vehicle
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createVehicle(string);

	

	
	
	
};

#endif