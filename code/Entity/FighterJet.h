/** @file FighterJet.h
 *  @brief This is the header file to create many entities.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef FighterJet_H
#define FighterJet_H

#include <string>
#include "Vehicle.h"
#include "Artillery.h"

using namespace std; 

class FighterJet: public Artillery
{


public: 

	/** Default constructor for fighterjet
    */
	FighterJet();
	/** Copy constructor for fighterjet
    */
	FighterJet(Artillery& v);

	/** A parameter constructer taht initializes 5 parameters inherits the variables from artillery class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */ 
	FighterJet(int,string,int,int,int); 
	
	/** Destructor 
    */
	virtual ~FighterJet(); 

	/** Function that decreases the fuel for the fighterjet
	*	@param int parameter take in an int variable represents
	*	the amount of fuel that should be decreased from the current amount of fuel 
	*/
	virtual void decreaseFeul(int);
	

	virtual Vehicle* clone();
	
	
};

#endif