#ifndef TRANSPORTVEHICLE_H
#define TRANSPORTVEHICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Vehicle.h"

using namespace std;

class TransportVehicle: public virtual Vehicle{
public:
	TransportVehicle(int hp, string c, int f);
	TransportVehicle(TransportVehicle& ent);
	~TransportVehicle();

	virtual Resource* clone();

	virtual bool carryEntity(Entity* ent);
	virtual Entity* dropOffEntity();
	virtual Entity* dropOffEntity(Entity* ent);

	virtual bool carryResource(Resource* ent);
	virtual Resource* dropOffResource();
	virtual Resource* dropOffResource(Resource* ent);

	virtual bool travel(int x, int y);
	virtual void die();

	///set/get

	int getEntityCapacity(){
		return entityCapacity;
	}
	int getResourceCapacity(){
		return resourceCapacity;
	}

	int getNumberOfEntities(){
		return (int) entities.size();
	}
	int getNumberOfResources(){
		return (int) resources.size();
	}

	virtual int getOverallStrength(){
		int str = HP;
		for(int i=0; i<(int)entities.size();i++){
			Entity* ent = entities[i];
			if(ent){
				str += ent->getOverallStrength();
			}
		}
		return str;
	}

protected:
	vector<Entity*> entities;
	vector<Resource*> resources;
	int entityCapacity = 1;
	int resourceCapacity = 1;
};

#endif