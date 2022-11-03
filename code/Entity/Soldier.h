/** @file Soldier.h
 *  @brief Class for one of our entities "Soldiers"
 *	@author Ayla 
 *  This class creates soldiers from regular citizens which are entities in our war simulator. 
 */

#ifndef SOLDIER_H
#define SOLDIER_H



#include <string>
#include "Citizen.h"

using namespace std; 

class Soldier : public Citizen
{

protected:


	string status = "NA"; /**<variable status that takes in a string*/




public: 
	/** Default constructor for the soldier*/
	Soldier();

	/**
	Soldeir constructor that takes in two parameters 

	@param int first parameter that takes in health of soldier 
	@param string second parameter that takes in country of soldier 
	@param string that takes in third parameter of the statistics 

	*/
	Soldier(int,string,string); 
	

	/** Deconstructer for the soldier*/
	virtual ~Soldier(); 


	


	
	


		
	
	
};

#endif