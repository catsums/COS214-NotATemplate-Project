#ifndef BASEWARPHASE_H
#define BASEWARPHASE_H

#include <iostream>
#include <vector>
#include <string>
#include "../Country/Country.h"

using namespace std;

/*	
	Phase for the War class inorder to handle the objects in the war class based on the specific state it has
	This is not a strategy as all the implementation for the functions are in the WarPhase
*/

class BaseWarPhase{
public:
	//create warphasestate with state as string
	BaseWarPhase(string s);
	~BaseWarPhase();
	//function to handle two sides of countries in the war
	virtual void handle(vector<Country*>* a, vector<Country*>* b) = 0;

	string getState();
private:
	string state;
};

#endif