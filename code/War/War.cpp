#ifndef WAR_CPP
#define WAR_CPP

#include <string>
#include <vector>

#include "Country.h"
#include "WarPhase.h"
#include "War.h"

War::War(){
	warState = new PhaseNeutral();
}
War::~War(){
	warState = NULL;
}

void War::changePhase(WarPhase* newState){
	warState = newState;
}
void War::handlePhase(){
	
	warState->handle(sideA, sideB);
}

#endif