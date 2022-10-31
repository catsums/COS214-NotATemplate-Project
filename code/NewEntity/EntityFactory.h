#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <iostream>
#include <iomanip>
#include <string>

#include "Entity.h"

using namespace std;

class EntityFactory{
public:
	EntityFactory(){

	}
	~EntityFactory(){

	}

	virtual Entity* createEntity(int hp, string country) = 0;
};