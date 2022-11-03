#ifndef WAR_H
#define WAR_H

#include <string>
#include <map>
#include <vector>

#include "../Country/Country.h"
#include "../SignalHandler/ObjectSignalBus.h"
#include "../ActionManager/ActionManager.h"
#include "../Adapter/Adapter.h"
#include "../Map/Map.h"
#include "WarPhase.h"

using namespace std;

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

	Country* getCountryByName(string n);

	vector<Country*>* getCountriesOnSide(int side);

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
		return handlers["warEvent"];
	}

	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}

	SignalBus* signalBus;
	ActionManager* actionManager;
	AdapterManager* adapterManager;
	SignalHandler* warHandler;
	Map* warMap;

private:
	int phaseCount;

	map<int,vector<Country*>*> sides;
	map<string, SignalHandler*> handlers;

	WarPhase* warState;
};

#endif