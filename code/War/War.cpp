#ifndef WAR_CPP
#define WAR_CPP

#include <string>
#include <vector>

#include "War.h"

using namespace std;

War::War(WarPhase* startState){
	warState = startState;

	handlers["warState"] = new FunctionHandler([this](SignalEvent* e){
        onWarPhaseChange(e);
    });

    signalBus = new SignalBus();

   	signalBus->subscribe("warState", handlers["warState"]);

    actionManager = new ActionManager();
    adapterManager = new AdapterManager();

    warMap = new Map();

    warMap->genStandardMap();
}
War::~War(){
	delete warState;
	warState = NULL;

	delete warMap;
	warMap = NULL;

	delete signalBus;
	signalBus = NULL;

	delete actionManager;
	actionManager = NULL;
	delete adapterManager;
	adapterManager = NULL;
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

void War::onWarPhaseChange(SignalEvent* _e){
	
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
Country* War::getCountryByName(string n){
	for(int i=0; i< (int) sides.size(); i++){
		vector<Country*>* sideA = sides[i];
		for(int j=0; j< (int) sideA->size(); j++){
			Country* country = (*sideA)[j];
			if(country && country->getName() == n){
				return country;
			}
		}
	}
	return NULL;
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
vector<Country*>* War::getCountriesOnSide(int side){
	if(side>=0 && side<sides.size()){
		return sides[side];
	}
	return NULL;
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