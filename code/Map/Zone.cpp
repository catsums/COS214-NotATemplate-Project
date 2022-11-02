#ifndef ZONE_CPP
#define ZONE_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Zone.h"

using namespace std;

//Parameterised constructor
Zone::Zone(int x, int y, int pv, bool l)
{
	pos.x = x; pos.y = y;
	this->productionValue = pv;
	this->land = l;
}

Zone::~Zone(){

}

//accessor methods
int Zone::getX(){ return pos.x; }
int Zone::getY(){ return pos.y; }
int Zone::getPv(){ return productionValue; }
bool Zone::isLand(){ return land; }

bool Zone::moveEntity(Entity* ent){
	if(addEntity(ent)){
		ent->travel(getPosition());
		return true;
	}
	return false;
}

bool Zone::addEntity(Entity* ent){
	if(!hasEntity(ent)){
		if((ent->canTravelLand() && isLand()) || (ent->canTravelSea() && !isLand())){
			entities[ent->getID()] = ent;
			return true;
		}
	}
	return false; //entity already in the zone
	
}
Entity* Zone::removeEntity(Entity* ent){
	Entity* _ent = NULL;
	if(hasEntity(ent)){
		_ent = entities[ent->getID()];
		entities.erase(ent->getID());
	}
	return _ent;
}

bool Zone::hasEntity(Entity* ent){
	if(!ent) return false;
	if(entities.count(ent->getID())>0){
		return (entities[ent->getID()]==ent);
	}
	return false;
}

bool Zone::addFacility(Facility* fac){
	if(!hasFacility(fac)){
		if((fac->isOnLand() && isLand()) || (fac->isOnSea() && !isLand())){
			facilities[fac->getID()] = fac;
			return true;
		}
	}
	return false;
}
Facility* Zone::removeFacility(Facility* fac){
	Facility* _fac = NULL;
	if(hasFacility(fac)){
		_fac = facilities[fac->getID()];
		facilities.erase(fac->getID());
	}
	return _fac;
}

bool Zone::hasFacility(Facility* fac){
	if(!fac) return false;
	if(facilities.count(fac->getID())>0){
		return (facilities[fac->getID()]==fac);
	}
	return false;
}

#endif