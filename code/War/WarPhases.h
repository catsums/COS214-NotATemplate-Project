/** @file WarPhases.h
*   @brief War phases are dealt with in these classes 
*
*	WarPhase that handles countries when they are in a neutral state. This means anything goes and is the default state
*/




#ifndef WARPHASES_H
#define WARPHASES_H

#include <iostream>
#include <iomanip>
#include <string>

#include "WarPhase.h"
#include "War.h"

using namespace std;

class PhaseNeutral: public WarPhase{
public:
	PhaseNeutral(War* war):WarPhase("neutral", war){

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
	PhasePeace(War* w):WarPhase(w,"peace"){

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
	PhaseOpenConflict(War* w):WarPhase(w,"openConflict"){

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
	PhaseCrisis(War* w):WarPhase(w,"crisis"){

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
	PhaseWar(War* w):WarPhase(w,"war"){

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
	PhaseNegotiations(War* w):WarPhase(w,"negotiations");
	~PhaseNegotiations(){

	}
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

#endif