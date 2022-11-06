/** @file BaseWarPhase.h
*  @brief War phases are dealt with in these classes 
*
*	Phase for the War class inorder to handle the objects in the war class based on the specific state it has
*	This is not a strategy as all the implementation for the functions are in the WarPhase	
*/

#ifndef BASEWARPHASE_H
#define BASEWARPHASE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Country/Country.h"

using namespace std;


class BaseWarPhase{
public:
	///create warphasestate with state as string
	BaseWarPhase(string s); /**<string variable inside constructor parameter*/
	~BaseWarPhase(); /**<Destructor*/
	///function to handle two sides of countries in the war
	virtual void handle(vector<Country*>* a, vector<Country*>* b) = 0;

	string getState(); /**<gets the state that the phase is currently in*/
private:
	string state; /**<State*/
};

#endif