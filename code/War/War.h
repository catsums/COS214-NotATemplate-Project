/** @file War.h
*  @brief War phases are dealt with in these classes 
*
*	War class that holds managers for the war objects in the whole system to aid with the engine,
*	as well as handle the warstate to allow for the countries in the war to implement strategies based on the states
*	This class also acts a mediator between many countries objects and the managers to allow for adapters to send signals
*
*	Most importantly, it handles the actionManager that allows for turns to be executed per turn
*/


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


class War{
public:
	///creates the war object with a specific war state
	/**
	*	@param BaseWarPhase pointer
	*/
	War(BaseWarPhase* startState); /**<Prameter constructor taking in a base war phase pointer*/
	~War(); /**Destructor*/
	
	/**
	*	@param BaseWarPhase pointer
	*/
	void changePhase(BaseWarPhase* newState); /**<changes the state of war object to a new phase*/
	
	void handlePhase(); /**<handles the warphase for all turns of the sides*/
	
	/**
	*	@param SignalEvent pointer
	*/
	void onWarPhaseChange(SignalEvent* _e); /**<function for handler to handle signalevents that relate to warState change*/

	/**
	*	@param Country pointer
	*	@param side that determines where the country would be
	*/
	void addCountry(Country* c, int side);/**<adds a country to the containers for countries based on a side*/
	
	/**
	*	@param Country pointer
	*	@param side that determines where the country would be
	*/
	void removeCountry(Country* c, int side); /**<removes country from the containers based on the side*/
	
	/**
	*	@param search country parameter takes in string of country
	*/
	Country* getCountryByName(string n); /**<get country based on the name by searching containers*/

	/**
	*	@param the side that will get a group of countries 
	*/	
	vector<Country*>* getCountriesOnSide(int side); /**<get a group of countries from the same side*/
	
	/**
	*	@param country parameter 
	*/
	int getSide(Country* c); /**<check for the side for this country or return -1 if it has no side*/
	///test function to output all the sides of the countries
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
	///function to get the handler for warState
	SignalHandler* getWarStateHandler(){
		return handlers["warState"];
	}
	///function to add a new event handler based on an event name
	/**
	*	@param string of name
	*	@param signal handler
	*/
	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	///function to remove a signalHandler based on the event name
	/**
	*	@param string of name
	*/
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}
	///function to get the signalHandler based on the event name
	/**
	*	@param string of name
	*/
	SignalHandler* getHandler(string n){
		if(handlers.count(n)>0){
			return handlers[n];
		}
		return NULL;
	}

	
	SignalBus* signalBus; /**<signalbus for War object to have objects listen to*/
	
	ActionManager* actionManager; /**<actionmanager to handler all commands*/
	
	AdapterManager* adapterManager; /**<adapter manager to store and reference all adapters being used*/
	
	Map* warMap; /**<Map of the war to be referenced and zones to be handled*/

protected:

	///incrementing the phases
	void incrementPhase(){
		phaseCount++;
	}

	///increment step
	void incrementStep(){
		if(step<maxStep){
			step++;
		}
	}
	
	int phaseCount = 0; /**<counts the number of phases accumulated based on change*/
	
	int step = 0; /**<counts number of steps accumulated*/
	///maximum number of steps allowed to take place in the war
	int maxStep = 9; /**<-1 means they will run for unlimited steps until the program is manually stopped*/


	
	map<int,vector<Country*>*> sides; /**<list of countries sorted in groups of countries per side*/
	
	map<string, SignalHandler*> handlers; /**<stores all of the handlers that will observe objects or handle events*/

	
	BaseWarPhase* warState; /**<current war state that allows the war object to behave in a certain way*/
};

#endif