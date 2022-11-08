/** @file EntityFactory.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */


#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <string>
#include "Citizen.h"
#include "Vehicle.h"


using namespace std; 

class EntityFactory
{

public: 

	/** Default constructor for citizen
    */
	EntityFactory(); 
	 
	/** Destructor 
    */
	virtual ~EntityFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it
	*/
	virtual Citizen* createCitizen();

	/** This function instantiates new vehicle entities 
	*	based on the string paramter value passed in,
	* 	it will know whether to be a land,sea or air vehicle
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createLandVehicle();
	virtual Vehicle* createAirVehicle();
	virtual Vehicle* createSeaVehicle();

	
	
	
};

#endif