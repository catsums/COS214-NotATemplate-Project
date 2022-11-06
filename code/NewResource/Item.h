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
		types.push_back("Item");
	}
	Item(int amt):Resource(){
		amount = amt;
		types.push_back("Item");
	}
	Item(Item& item):Resource(item){
		amount = item.amount;
		types.push_back("Item");
	}
	~Item(){

	}

	virtual Resource* clone() = 0;

	virtual Entity* useOn(Entity* ent) = 0;

	int getAmount(){
		return amount;
	}
protected:
	int amount = 1;
};

#endif