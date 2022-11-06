/** @file WarPhase.h
*   @brief War phases are dealt with in these classes 
*
*	WarPhase object takes a war object in order to implement the state methods for the War object and uses Dependancy injection
*	to allow the WarPhase and WarPhase to refer to each other simultaneously
*/


#ifndef WARPHASE_H
#define WARPHASE_H

#include <iostream>
#include <vector>
#include <string>
#include "BaseWarPhase.h"
#include "War.h"

using namespace std;


class WarPhase: public BaseWarPhase{
public:
	
	/**
	*	@param war pointer 
	*	@param state name
	*/
	WarPhase(War* _war, string s); /**<creates warphase object with war obj and state name*/
	~WarPhase(); /**<Destructor*/

	/**
	*	@param country pointer a 
	*	@param country pointer b
	*/	
	virtual void handle(vector<Country*>* a, vector<Country*>* b); /**<function handles two sides of objects in the war*/
	///setter for war object
	void setWarObject(War* w){
		war = w;
	}
	///getter for war object
	War* getWarObject(){
		return war;
	}
private:
	
	War* war; /**<war object that uses this specific warphase to behave*/
};

#endif
