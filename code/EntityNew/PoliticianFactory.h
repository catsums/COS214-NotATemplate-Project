/** @file PoliticianFactory.h
 *  @brief This is the header file to create many citizens of type politician.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef POLITICIANFACTORY_H
#define POLITICIANFACTORY_H

#include <string>
#include "Citizen.h"

using namespace std; 

class PoliticianFactory: public CitizenFactory
{

protected:

	Citizen * myCitizen; /**<A variable of type citizen*/

public: 

	/** Default constructor for politician
    */
	PoliticianFactory(); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from the soldier factory class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */

	PoliticianFactory(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~PoliticianFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it. A pure virtual 
	*	function inherets from Entity factory.
	*/
	virtual Citizen* createCitizen();
	
	
	
};

#endif