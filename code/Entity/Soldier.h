/** @file Soldier.h
 *  @brief This is the header file to create the soldier class.
 *
 *  Creating an entity class allows us to create our various elements that are invloved in the war
 *  an example of an entity is a Citizen after creating a citizen we must establish the different 
 *	types of citizens and their role in the war. This is one of them. 
 */



#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Soldier: public Citizen
{


public: 

	/** Default constructor for informant
    */
	Soldier();
	/** Copy constructor for informant
    */
	Soldier(Citizen& ent);

	/** A parameter constructer taht initializes 5 parameters inherits the variables from the citizen class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	Soldier(int,string,int,int,int);
	

	/** Destructor
    */
	virtual ~Soldier(); 

	

	
	
	
};

#endif