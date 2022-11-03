/** @file TankFactory.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or Artillerys
 * 
 */


#ifndef TankFACTORY_H
#define TankFACTORY_H

#include <string>
#include "Artillery.h"
#include "Vehicle.h"


using namespace std; 

class TankFactory:public ArtilleryFactory
{

protected:

	Vehicle * myVehicle;

public: 

	/** Default constructor for citizen
    */
	TankFactory(); 
	 
	/** Destructor 
    */
	virtual ~TankFactory(); 

	/** This function instantiates new Artillery entities 
	*	based on the string paramter value passed in,
	* 	it will know whether to be a land,sea or air Artillery
	* 	and returns a refernce to it
	*/
	virtual Vehicle* createVehicle();

	

	
	
	
};

#endif