#ifndef TRANSPORTVEHICLE_CPP
#define TRANSPORTVEHICLE_CPP

#include "TransportVehicle.h"

using namespace std;

TransportVehicle::TransportVehicle(int hp, string c, int f):Vehicle(hp,c,f){
	type = "TransportVehicle";
}
TransportVehicle::TransportVehicle(TransportVehicle& ent):Vehicle(ent){
	type = "TransportVehicle";
	capacity = ent.capacity;
}

Resource* TransportVehicle::clone(){
	return new TransportVehicle(*this);
}

bool TransportVehicle::carryEntity(Entity* ent){
	if(entities.size() < capacity){
		entities.push_back(ent);
		ent->setPosition(zone);
		return true;
	}
	return false;
}

Entity* TransportVehicle::dropOff(){
	if(!entities.empty()){
		Entity* ent = entities.back();
		entities.pop_back();
		return ent;
	}
	return NULL;
}

Entity* TransportVehicle::dropOff(Entity* ent){
	if(!entities.empty()){
		for(int i=0;i<(int)entities.size();i++){
			if(entities[i] == ent){
				Entity* res = entities[i];
				entities.erase(entities.begin()+i);
				return res;
			}
		}
	}
	return NULL;
}

bool TransportVehicle::travel(int x, int y){
	bool canTravel = Vehicle::travel(x,y);

	if(canTravel){
		for(int i=0; i<(int)entities.size();i++){
			Entity* ent = entities[i];
			ent->setPosition(zone);
		}
	}
	return canTravel;
}

#endif