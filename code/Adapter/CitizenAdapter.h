#ifndef CITIZENADAPTER_H
#define CITIZENADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Citizen.h"
#include "EntityAdapter.h"

using namespace std;

class CitizenAdapter: public EntityAdapter{
public:
	CitizenAdapter(Citizen* ent, AdapterManager* mng);
	~CitizenAdapter();

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//Entity stuffs
	virtual string getInfluence();

	// virtual bool takeDamage(int dmg);
	// virtual bool travel();
	// virtual bool attack(EntityAdapter* adp);
	// virtual bool attack(string id);
protected:
}

#endif