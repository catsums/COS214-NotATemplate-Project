#ifndef ENTITYADAPTER_H
#define ENTITYADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Adapter.h"

using namespace std;

class EntityAdapter: public Adapter{
public:
	EntityAdapter(AdapterManager* mng);
	~EntityAdapter();

	virtual void action(string actionName);

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//Entity Getters
	virtual int getHP() = 0;
	virtual string getCountry() = 0;
	virtual bool isAlive() = 0;

	virtual bool takeDamage(int dmg) = 0;
	virtual bool travel() = 0;
protected:
	SignalHandler* entityHandler;
};

#endif