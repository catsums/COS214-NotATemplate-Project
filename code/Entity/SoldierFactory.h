/** @file SoldierFactory.h
 *  @brief This is the header file to create many citizens of type soldier.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef SOLDIERFACTORY_H
#define SOLDIERFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class SoldierFactory: public CitizenFactory
{

protected:

	Citizen * myCitizen; /**<A variable of type citizen*/

public: 

	/** Default constructor for soldier
    */
	SoldierFactory(); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from the soldier factory class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */

	SoldierFactory(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~SoldierFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it. A pure virtual 
	*	function inherets from Entity factory.
	*/
	virtual Citizen* createCitizen();
	
	
	
};

#endif