#ifndef WAR_H
#define WAR_H

#include <string>
#include <vector>

#include "Country.h"
#include "WarPhase.h"

class War{
public:
	War();
	~War();
	void changePhase(WarPhase* newState); //change warstate

	void handlePhase(); //execute phase

private:
	int phaseCount;

	vector<Country*> sideA;
	vector<Country*> sideB;

	WarPhase* warState;
};

#endif