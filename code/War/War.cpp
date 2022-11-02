#ifndef WAR_CPP
#define WAR_CPP

#include <string>
#include <vector>

#include "War.h"

using namespace std;

War::War(){
	warState = new PhaseNeutral();

    warHandler = new FunctionHandler([this](SignalEvent* e){
        onWarEvent(e);
    });

    signalBus = new SignalBus();

    signalBus->subscribe("warState", warHandler);

    actionManager = new ActionManager();

    warMap = new Map();
}
War::War(WarPhase* startState){
	warState = startState;

	warHandler = new FunctionHandler([this](SignalEvent* e){
        onWarEvent(e);
    });

    signalBus = new SignalBus();

    signalBus->subscribe("warState", warHandler);

    actionManager = new ActionManager();
}
War::~War(){
	delete warState;
	warState = NULL;

	delete warHandler;
	warHandler = NULL;

	delete signalBus;
	signalBus = NULL;

	delete actionManager;
	actionManager = NULL;
}

void War::changePhase(WarPhase* newState){
	warState = newState;
}
void War::handlePhase(){
	
	for(int i=0; i< (int) sides.size(); i++){
		vector<Country*>* sideA = sides[i];
		for(int j=0; j< (int) sides.size(); j++){
			vector<Country*>* sideB = sides[j];
			if(sideA != sideB){
				warState->handle(sideA, sideB);
			}
		}
	}

	
}

void War::onWarEvent(SignalEvent* _e){
	
	ObjectSignalEvent<string>* e = static_cast<ObjectSignalEvent<string>*>(_e);

	string data = *(e->data);

	if(data != warState->getState()){
		WarPhase* newState;
		if(data == "neutral") newState = new PhaseNeutral();
		if(data == "peace") newState = new PhasePeace();
		if(data == "war") newState = new PhaseWar();
		if(data == "crisis") newState = new PhaseCrisis();
		if(data == "negotiations") newState = new PhaseNegotiations();
		
		changePhase(newState);
	}
}

void War::addCountry(Country* c, int side){
	if(!sides[side]){
		sides[side] = new vector<Country*>();
	}
	sides[side]->push_back(c);
}
void War::removeCountry(Country* c, int side){
	if(sides[side]){
		vector<Country*>* _side = sides[side];
		for(int i=0; i<(int)_side->size();i++){
			if(c == (*_side)[i]){
				_side->erase(_side->begin()+i);
				return;
			}
		}
	}
}
int War::getSide(Country* c){
	
	for(int i=0; i< (int) sides.size(); i++){
		vector<Country*>* sideA = sides[i];
		for(int j=0; j< (int) sideA->size(); j++){
			Country* country = (*sideA)[j];
			if(country == c){
				return i;
			}
		}
	}
	return -1; //means country has no side
}


#endif