/** @file Medic.h
 *  @brief This is the header file to create the medic class.
 *
 *  Creating an entity class allows us to create our various elements that are invloved in the war
 *  an example of an entity is a Citizen after creating a citizen we must establish the different 
 *	types of citizens and their role in the war. This is one of them. 
 */

#ifndef MEDIC_H
#define MEDIC_H

#include <string>
#include "Citizen.h"

using namespace std; 

class Medic: public Citizen
{

private:

	int healAmount; /**int variable representing the heal amount the medic has*/


public: 


 	/** Default constructor for informant
    */
	Medic(); 

	/** A parameter constructer taht initializes 5 parameters inherits the variables from the citizen class  
	*
	*	@param int variable that represents the health
	*	@param string variable that represents the country
	*	@param int variable that represents the damage
	*	@param int variable that represents the x-coordinates
	*	@param int variable that represents the y-coordinates 
    */
	Medic(int,string,int,int,int);
	

	/** Destructor
    */
	virtual ~Medic(); 

	//Getters
	
	/** This function will provide health to other entities.
	*	It returns an integer value that will be added to an entity's health
	*/
	int getHeal();

	///Setters

	/** This function will set the health to other entities.
	*	@param int variable that sets the health the medic has to offer 
	*/
	void setHeal(int h);




	
	

	

	
	
	
};

#endif