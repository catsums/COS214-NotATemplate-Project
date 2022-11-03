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

class EntityAdapter: public Adapter{
public:
	EntityAdapter(Entity* ent);
	~EntityAdapter();

	virtual void action(map<string,string> data);

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//request stuff
	virtual ActionRequest* requestAttack(string target);
	virtual ActionRequest* requestHeal(int amt);
	virtual ActionRequest* requestTakeDamage(int amt);
	virtual ActionRequest* requestTravel(Zone* zone);
	virtual ActionRequest* requestDeath();

	//Entity stuff
	virtual int getHP();
	virtual string getCountry();
	virtual bool isAlive();
	virtual Position getPosition();

	virtual Zone* getZone(Map* zoneMap);

	virtual bool takeDamage(int dmg);
	virtual bool heal(int amt);
	virtual bool travel(int x, int y);
	virtual bool travelToZone(Zone* z);
	virtual bool attack(EntityAdapter* adp);
	virtual bool attack(string id);
	virtual bool die();

	virtual bool canTravelSea();
	virtual bool canTravelLand();

	Entity* getEntity(){
		return entity;
	}
protected:
	SignalHandler* entityHandler;
	Entity* entity;
};

#endif