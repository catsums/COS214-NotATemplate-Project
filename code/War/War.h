#ifndef WAR_H
#define WAR_H

#include <string>
#include <map>
#include <vector>

#include "../Country/Country.h"
#include "../SignalHandler/ObjectSignalBus.h"
#include "../ActionManager/ActionManager.h"
#include "../Adapter/Adapter.h"
#include "../Adapter/AdapterWrapper.h"
#include "../Map/Map.h"
#include "BaseWarPhase.h"

using namespace std;

/*	
	War class that holds managers for the war objects in the whole system to aid with the engine,
	as well as handle the warstate to allow for the countries in the war to implement strategies based on the states
	This class also acts a mediator between many countries objects and the managers to allow for adapters to send signals

	Most importantly, it handles the actionManager that allows for turns to be executed per turn
*/

class War{
public:
	//creates the war object with a specific war state
	War(BaseWarPhase* startState);
	~War();
	//changes the state of war object to a new phase
	void changePhase(BaseWarPhase* newState);
	//handles the warphase for all turns of the sides
	void handlePhase(); 
	//function for handler to handle signalevents that relate to warState change
	void onWarPhaseChange(SignalEvent* _e);

	//adds a country to the containers for countries based on a side
	void addCountry(Country* c, int side);
	//removes country from the containers based on the side
	void removeCountry(Country* c, int side);
	//get country based on the name by searching containers
	Country* getCountryByName(string n);
	//get a group of countries from the same side
	vector<Country*>* getCountriesOnSide(int side);
	//check for the side for this country or return -1 if it has no side
	int getSide(Country* c); 
	//test function to output all the sides of the countries
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
	//function to get the handler for warState
	SignalHandler* getWarStateHandler(){
		return handlers["warState"];
	}
	//function to add a new event handler based on an event name
	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	//function to remove a signalHandler based on the event name
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}
	//function to get the signalHandler based on the event name
	SignalHandler* getHandler(string n){
		if(handlers.count(n)>0){
			return handlers[n];
		}
		return NULL;
	}

	//signalbus for War object to have objects listen to
	SignalBus* signalBus;
	//actionmanager to handler all commands
	ActionManager* actionManager;
	//adapter manager to store and reference all adapters being used
	AdapterManager* adapterManager;
	//Map of the war to be referenced and zones to be handled
	Map* warMap;

protected:
	void incrementPhase(){
		phaseCount++;
	}
	void incrementStep(){
		if(step<maxStep){
			step++;
		}
	}
	//counts the number of phases accumulated based on change
	int phaseCount = 0;
	//counts number of steps accumulated
	int step = 0;
	//maximum number of steps allowed to take place in the war
	int maxStep = 9; //-1 means they will run for unlimited steps until the program is manually stopped


	//list of countries sorted in groups of countries per side
	map<int,vector<Country*>*> sides;
	//stores all of the handlers that will observe objects or handle events
	map<string, SignalHandler*> handlers;

	//current war state that allows the war object to behave in a certain way
	BaseWarPhase* warState;
};

#endif