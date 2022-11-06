/** @file EntityAdapter.h
*	@brief An example of how we incorporated the adapter pattern into our war simulator 
*/


#ifndef ENTITYADAPTER_H
#define ENTITYADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <initializer_list>

#include <functional>

#include "Adapter.h"
#include "../Map/Map.h"

using namespace std;

/**	
*	An Adapter that wraps around an entity in order to make use of its functionality and allow it to handle and create requests
*/

class EntityAdapter: public Adapter{
public:
	///creates adapter by wrapping around the entity
	/** Parameter constructor that takes in a entity pointer
	*	@param entity pointer 
	*/
	EntityAdapter(Entity* ent);
	//Destrcutor
	~EntityAdapter();

	
	virtual void action(map<string,string> data);/**<executes action based on the result data from request*/

	///default handlers for processing and request finishing respectively
	virtual void onHandle(SignalEvent* e); 
	virtual void onFulFilled(SignalEvent* e);

	
	virtual ActionRequest* requestAttack(string target);/**<creates a request to attack based on the id of target*/
	
	virtual ActionRequest* requestHeal(int amt); /**<creates a request to heal a certain amount*/
	
	virtual ActionRequest* requestTakeDamage(int amt);/**<creates a request to take damage a certain amt*/
	
	virtual ActionRequest* requestTravel(Zone* zone); /**<creates a request to travel to a specific zone*/
	
	virtual ActionRequest* requestDeath(); /**<creates a request to go to heaven*/

	
	virtual int getHP(); /**<gets the hp of entity*/
	
	virtual string getCountry(); /**gets the country name of entity*/
	
	virtual bool isAlive(); /**<checks if entity is alive*/
	
	virtual Position getPosition(); /**<checks the current position of the entity*/
	
	virtual Zone* getZone(Map* zoneMap); /**<gets the current zone the entity resides in based on the map*/

	
	virtual bool takeDamage(int dmg); /**<runs the takeDamage() for entity*/
	
	virtual bool heal(int amt); /**<runs the heal() for entity*/
	
	virtual bool travel(int x, int y); /**<runs travel for entity*/
	
	virtual bool travelToZone(Zone* z); /**<runs travel for entity using a zone*/
	
	virtual bool attack(EntityAdapter* adp); /**<runs the attack() for entity towards a target*/
	virtual bool attack(string id);
	
	virtual bool die(); /**<runs die() for entity*/

	
	virtual bool canTravelSea(); /**<checks if entity can travel on sea*/
	
	virtual bool canTravelLand(); /**<checks if entity can travel on air*/
	///gets adaptee
	Entity* getEntity(){
		return entity;
	}
protected:
	SignalHandler* entityHandler; /**<the handler for the entity*/
	Entity* entity; /**<the adaptee*/
};

#endif