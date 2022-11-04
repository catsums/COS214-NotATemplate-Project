/** @file CitizenFactory.h
 *  @brief This is the header file to create many citizen.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class CitizenFactory: public EntityFactory
{


public: 

	/** Default constructor for citizen
    */
	CitizenFactory();
	
	/** Destructor 
    */
	virtual ~CitizenFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it. A pure virtual 
	*	function inherets from Entity factory.
	*/
	virtual Citizen* createCitizen()=0;
	

	
	
	
};

#endif