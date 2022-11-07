/** @file ArtilleryFactory.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef ArtilleryFACTORY_H
#define ArtilleryFACTORY_H

#include <string>
#include "VehicleFactory.h"


using namespace std; 

class ArtilleryFactory:public VehicleFactory
{
protected:

	Vehicle * myVehicle;

public: 

	/** Default constructor for artillery
    */
	ArtilleryFactory(); 
	 
	/** Destructor 
    */
	virtual ~ArtilleryFactory(); 

	/** This function instantiates new vehicle entities 
	*	based on the string parameter value passed in,
	* 	it will know whether to be a land,sea or air vehicle
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createLandVehicle();
	virtual Vehicle* createAirVehicle();
	virtual Vehicle* createSeaVehicle();

	

	
	
	
};

#endif