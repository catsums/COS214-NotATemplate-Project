#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Resource.h"

class Item: public Resource{
	Item();
	~Item();

	virtual void useOn(Entity* ent) = 0;
}

#endif