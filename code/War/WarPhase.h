#ifndef WARPHASE_H
#define WARPHASE_H

#include <iostream>
#include <vector>
#include <string>
#include "BaseWarPhase.h"
#include "War.h"

using namespace std;

/*	
	WarPhase object takes a war object in order to implement the state methods for the War object and uses Dependancy injection
	to allow the WarPhase and WarPhase to refer to each other simultaneously
*/

class WarPhase: public BaseWarPhase{
public:
	//creates warphase object with war obj and state name
	WarPhase(War* _war, string s);
	~WarPhase();
	//function handles two sides of objects in the war
	virtual void handle(vector<Country*>* a, vector<Country*>* b);
	//setter for war object
	void setWarObject(War* w){
		war = w;
	}
	//getter for war object
	War* getWarObject(){
		return war;
	}
private:
	//war object that uses this specific warphase to behave
	War* war;
};

#endif
