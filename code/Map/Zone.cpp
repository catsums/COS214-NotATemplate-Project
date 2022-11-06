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
Zone::Zone(int x, int y, bool l)
{
	pos.x = x; pos.y = y;
	land = l;
	country = "";
}
Zone::Zone(int x, int y, bool l, string c)
{
	pos.x = x; pos.y = y;
	land = l;
	country = c;
}


Zone::~Zone(){

}

//accessor methods
int Zone::getX(){ return pos.x; }
int Zone::getY(){ return pos.y; }
bool Zone::isLand(){ return land; }

bool Zone::moveEntity(Entity* ent){
	if(addEntity(ent)){
		ent->travel(getPosition());
		return true;
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