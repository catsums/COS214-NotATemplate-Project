#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Resource.h"
#include "../NewEntity/Entity.h"

class Item: public Resource{
public:
	Item():Resource(){

	}
	Item(int amt):Resource(){
		amount = amt;
	}
	Item(Item& item):Resource(){
		amount = item.amount;
	}
	~Item(){

	}

	virtual Resource* clone() = 0;

	virtual void useOn(Entity* ent) = 0;

	int getAmount(){
		return amount;
	}
protected:
	int amount = 1;
};

#endif