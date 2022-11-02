#ifndef WAR_H
#define WAR_H

#include <string>
#include <map>
#include <vector>

#include "../Country/Country.h"
#include "../SignalHandler/SignalHandler.h"
#include "../ActionManager/ActionManager.h"
#include "../Adapter/Adapter.h"
#include "../Map/Map.h"
#include "WarPhase.h"

class War{
public:
	War();
	War(WarPhase* startState);
	~War();

	void changePhase(WarPhase* newState); //change warstate

	void handlePhase(); //execute phase
	void onWarEvent(SignalEvent* _e);

	void addCountry(Country* c, int side);
	void removeCountry(Country* c, int side);

	int getSide(Country* c);

	void printSides(){
		for(int i=0; i< (int) sides.size(); i++){
			vector<Country*>* sideA = sides[i];
			cout<<"Side "<<i<<":"<<endl;
			for(int j=0; j< (int) sideA->size(); j++){
				Country* country = (*sideA)[j];
				cout<<j<<" - "<<country->getName()<<endl;
			}
		}
	}

	SignalHandler* getWarHandler(){
		return warHandler;
	}

private:
	int phaseCount;

	map<int,vector<Country*>*> sides;

	SignalHandler* warHandler;
	SignalBus* signalBus;
	ActionManager* actionManager;
	Map* warMap;

	WarPhase* warState;
};

#endif