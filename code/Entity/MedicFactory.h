/** @file MedicFactory.h
 *  @brief This is the header file to create many citizens of type medic.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef MEDICFACTORY_H
#define MEDICFACTORY_H

#include <string>
#include "CitizenFactory.h"

using namespace std; 

class MedicFactory: public CitizenFactory
{

protected:

	Citizen * myCitizen; /**<A variable of type citizen*/

public: 

	/** Default constructor for medic
    */
	MedicFactory(); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from the soldier factory class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */

	MedicFactory(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~MedicFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it. A pure virtual 
	*	function inherets from Entity factory.
	*/
	virtual Citizen* createCitizen();
	
	
	
};

#endif