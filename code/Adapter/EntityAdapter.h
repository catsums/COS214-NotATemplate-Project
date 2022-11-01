#ifndef ENTITYADAPTER_H
#define ENTITYADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Adapter.h"
#include "../Map/Map.h"
#include "../NewEntity/Entity.h"

using namespace std;

class EntityAdapter: public Adapter{
public:
	EntityAdapter(Entity* ent, AdapterManager* mng);
	~EntityAdapter();

	virtual void action(string actionName);

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//Entity stuff
	virtual int getHP();
	virtual string getCountry();
	virtual bool isAlive();
	virtual map<string,int> getPosition();

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