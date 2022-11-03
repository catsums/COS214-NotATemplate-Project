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

/*	
	An Adapter that wraps around an entity in order to make use of its functionality and allow it to handle and create requests
*/

class EntityAdapter: public Adapter{
public:
	//creates adapter by wrapping around the entity
	EntityAdapter(Entity* ent);
	~EntityAdapter();

	//executes action based on the result data from request
	virtual void action(map<string,string> data);

	//default handlers for processing and request finishing respectively
	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//creates a request to attack based on the id of target
	virtual ActionRequest* requestAttack(string target);
	//creates a request to heal a certain amount
	virtual ActionRequest* requestHeal(int amt);
	//creates a request to take damage a certain amt
	virtual ActionRequest* requestTakeDamage(int amt);
	//creates a request to travel to a specific zone
	virtual ActionRequest* requestTravel(Zone* zone);
	//creates a request to go to heaven
	virtual ActionRequest* requestDeath();

	//gets the hp of entity
	virtual int getHP();
	//gets the country name of entity
	virtual string getCountry();
	//checks if entity is alive
	virtual bool isAlive();
	//checks the current position of the entity
	virtual Position getPosition();
	//gets the current zone the entity resides in based on the map
	virtual Zone* getZone(Map* zoneMap);

	//runs the takeDamage() for entity
	virtual bool takeDamage(int dmg);
	//runs the heal() for entity
	virtual bool heal(int amt);
	//runs travel for entity
	virtual bool travel(int x, int y);
	//runs travel for entity using a zone
	virtual bool travelToZone(Zone* z);
	//runs the attack() for entity towards a target
	virtual bool attack(EntityAdapter* adp);
	virtual bool attack(string id);
	//runs die() for entity
	virtual bool die();

	//checks if entity can travel on sea
	virtual bool canTravelSea();
	//checks if entity can travel on air
	virtual bool canTravelLand();
	//gets adaptee
	Entity* getEntity(){
		return entity;
	}
protected:
	SignalHandler* entityHandler; //the handler for the entity
	Entity* entity; //the adaptee
};

#endif