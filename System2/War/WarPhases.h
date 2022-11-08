#ifndef WARPHASES_H
#define WARPHASES_H

#include <iostream>
#include <iomanip>
#include <string>

#include "WarPhase.h"
#include "War.h"

using namespace std;

/*	
	WarPhase that handles countries when they are in a neutral state. This means anything goes and is the default state
*/

class PhaseNeutral: public WarPhase{
public:
	PhaseNeutral():WarPhase("neutral"){

	}
	~PhaseNeutral(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){
		WarPhase::handle(a,b);
	}
};

/*	
	WarPhase that handles countries when they are in peace
*/

class PhasePeace: public WarPhase{
public:
	PhasePeace():WarPhase("peace"){

	}
	~PhasePeace(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}

};

/*	
	WarPhase that handles countries when they are in an open conflict but not a true war
*/

class PhaseOpenConflict: public WarPhase{
public:
	PhaseOpenConflict():WarPhase("openConflict"){

	}
	~PhaseOpenConflict(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/*	
	WarPhase that handles countries when they are in a crisis
*/

class PhaseCrisis: public WarPhase{
public:
	PhaseCrisis():WarPhase("crisis"){

	}
	~PhaseCrisis(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/*	
	WarPhase that handles countries when they are in a full on war
*/

class PhaseWar: public WarPhase{
public:
	PhaseWar():WarPhase("war"){

	}
	~PhaseWar(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/*	
	WarPhase that handles countries when they are in a negotiations
*/

class PhaseNegotiations: public WarPhase{
public:
	PhaseNegotiations():WarPhase("negotiations"){
		
	}
	~PhaseNegotiations(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

#endif