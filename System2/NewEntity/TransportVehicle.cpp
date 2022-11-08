#ifndef TRANSPORTVEHICLE_CPP
#define TRANSPORTVEHICLE_CPP

#include "TransportVehicle.h"

using namespace std;

TransportVehicle::TransportVehicle(int hp, int f):Vehicle(hp,f){
	Entity::types.push_back("TransportVehicle");
	Resource::types.push_back("TransportVehicle");
}
TransportVehicle::TransportVehicle(int hp, string c, int f):Vehicle(hp,c,f){
	Entity::types.push_back("TransportVehicle");
	Resource::types.push_back("TransportVehicle");
}
TransportVehicle::TransportVehicle(TransportVehicle& ent):Vehicle(ent){
	Entity::types.push_back("TransportVehicle");
	Resource::types.push_back("TransportVehicle");
	entityCapacity = ent.entityCapacity;
	resourceCapacity = ent.resourceCapacity;
}

TransportVehicle::~TransportVehicle(){
	
}

Resource* TransportVehicle::clone(){
	return new TransportVehicle(*this);
}

bool TransportVehicle::carryEntity(Entity* ent){
	if(entities.size() < entityCapacity){
		entities.push_back(ent);
		ent->setPosition(zone);
		return true;
	}
	return false;
}

Entity* TransportVehicle::dropOffEntity(){
	if(!entities.empty()){
		Entity* ent = entities.back();
		entities.pop_back();
		return ent;
	}
	return NULL;
}

Entity* TransportVehicle::dropOffEntity(Entity* ent){
	if(!entities.empty()){
		for(int i=0;i<(int)entities.size();i++){
			if(entities[i] == ent){
				Entity* _ent = entities[i];
				entities.erase(entities.begin()+i);
				return _ent;
			}
		}
	}
	return NULL;
}

bool TransportVehicle::carryResource(Resource* reso){
	if(resources.size() < resourceCapacity){
		resources.push_back(reso);
		return true;
	}
	return false;
}

Resource* TransportVehicle::dropOffResource(){
	if(!resources.empty()){
		Resource* reso = resources.back();
		resources.pop_back();
		return reso;
	}
	return NULL;
}

Resource* TransportVehicle::dropOffResource(Resource* reso){
	if(!resources.empty()){
		for(int i=0;i<(int)resources.size();i++){
			if(resources[i] == reso){
				Resource* _reso = resources[i];
				resources.erase(resources.begin()+i);
				return _reso;
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

void TransportVehicle::die(){
	Vehicle::die();
	for(int i=0; i<(int)entities.size();i++){
		Entity* ent = entities[i];
		ent->die();
	}
}

#endif