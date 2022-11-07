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

	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a neutral war
	*/
	PhaseNeutral(War* war):WarPhase("neutral", war){

	}

	///Destructor
	~PhaseNeutral(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){
		WarPhase::handle(a,b);
	}
};

/**	
*	WarPhase that handles countries when they are in peace
*/

class PhasePeace: public WarPhase{
public:
	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a peaceful war
	*/
	PhasePeace(War* w):WarPhase(w,"peace"){

	}
	///Destructor
	~PhasePeace(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){

	}

};

/*	
	WarPhase that handles countries when they are in an open conflict but not a true war
*/

class PhaseOpenConflict: public WarPhase{
public:

	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a war in open conflict
	*/
	PhaseOpenConflict(War* w):WarPhase(w,"openConflict"){

	}
	///Destructor
	~PhaseOpenConflict(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/**	
*	WarPhase that handles countries when they are in a crisis
*/

class PhaseCrisis: public WarPhase{
public:

	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a war in crisis
	*/
	PhaseCrisis(War* w):WarPhase(w,"crisis"){

	}
	///Destructor
	~PhaseCrisis(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/**	
*	WarPhase that handles countries when they are in a full on war
*/

class PhaseWar: public WarPhase{
public:

	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a war currently happening 
	*/
	PhaseWar(War* w):WarPhase(w,"war"){

	}

	///Destructor
	~PhaseWar(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

/**	
*	WarPhase that handles countries when they are in a negotiations
*/

class PhaseNegotiations: public WarPhase{
public:
	/** Parameter contructor 
	*	@param war pointer 
	*	Inherits from war phase this represents a negotiations in war
	*/
	PhaseNegotiations(War* w):WarPhase(w,"negotiations");
	///Destructor
	~PhaseNegotiations(){

	}

	/** Handles the war phase
	*	@param vector a 
	*	@param vector b
	*/
	void handle(vector<Country*>* a, vector<Country*>* b){

	}
};

#endif