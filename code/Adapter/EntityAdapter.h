#ifndef ENTITYADAPTER_H
#define ENTITYADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Adapter.h"
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

	virtual bool takeDamage(int dmg) = 0;
	virtual bool heal(int amt) = 0;
	virtual bool travel(int x, int y) = 0;
	virtual bool attack(EntityAdapter* adp) = 0;
	virtual bool attack(string id) = 0;
	virtual bool die() = 0;

	Entity* getEntity(){
		return entity;
	}
protected:
	SignalHandler* entityHandler;
	Entity* entity;
};

#endif