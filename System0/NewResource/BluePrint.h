#ifndef BLUEPRINT_H
#define BLUEPRINT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Resource.h"
#include "../NewEntity/Vehicle.h"

class BluePrint: public Item{
public:
	BluePrint(Vehicle* _base):Item(1){
		base* = _base;
		types.push_back("BluePrint");
	}
	BluePrint(Item& item):Item(item){
		base = _base;
		types.push_back("BluePrint");
	}
	~BluePrint(){
		base = NULL;
	}

	virtual Resource* clone(){
		return new BluePrint(*this);
	}

	virtual Entity* useOn(Entity* ent){
		Entity* newEnt = NULL;
		if(amount>0 && !used){
			newEnt = base->clone();
			amount--;
			if(amount<=0){
				used = true;
			}
		}
		return ent;
	}

	virtual Entity* build() = 0;

	int getAmount(){
		return amount;
	}
protected:
	Vehicle* base;
};

#endif