#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Entity.h"

using namespace std;

class Resource{
public:
	Resource(){
		used = false;
	}
	~Resource(){

	}

	virtual void useOn(Entity* ent) = 0;
	virtual Resource* clone() = 0;

	bool isUsed(){
		return used;
	}
protected:
	bool used;
};

#endif