#ifndef ENTITYADAPTER_CPP
#define ENTITYADAPTER_CPP

#include "EntityAdapter.h"

using namespace std;

EntityAdapter::EntityAdapter(Entity* ent, AdapterManager* mng):Adapter(mng){
	types.push_back("ENTITY");
	entity = ent;
}
EntityAdapter::~EntityAdapter(){
	entity = NULL;
}

void EntityAdapter::action(string actionName){

}

int EntityAdapter::getHP(){
	if(entity){
		return entity->getHP();
	}
	return 0;
}
string EntityAdapter::getCountry(){
	if(entity){
		return entity->getCountry();
	}
	return "";
}
bool EntityAdapter::isAlive(){
	if(entity){
		return entity->isAlive();
	}
	return false;
}
Position EntityAdapter::getPosition(){
	if(entity){
		return entity->getPosition();
	}
	return Position(0,0);
}

Zone* EntityAdapter::getZone(Map* zoneMap){
	if(zoneMap && entity){
		Position pos = entity->getPosition();
		return zoneMap->getZone(pos.x,pos.y);
	}
	return NULL;
}

bool EntityAdapter::takeDamage(int dmg){
	if(entity){
		return entity->takeDamage(dmg);
	}
	return false;
}
bool EntityAdapter::heal(int amt){
	if(entity){
		return entity->heal(amt);
	}
	return false;
}
bool EntityAdapter::travel(int x,int y){
	if(entity){
		entity->travel(x,y);
		return true;
	}
	return false;
}
bool EntityAdapter::travelToZone(Zone* z){
	if(entity && z){
		if( z->isLand() && entity->canTravelLand() || !z->isLand() && entity->canTravelSea() ){
			z->moveEntity(entity);
			return true;
		}
	}
	return false;
}
bool EntityAdapter::attack(EntityAdapter* adp){
	if(entity && adp->getEntity()){
		entity->attack(adp->getEntity());
		return true;
	}
	return false;
}
bool EntityAdapter::attack(string id){
	BaseAdapter* adp = manager->getAdapter("ENTITY",id);
	if(adp){
		try{
			EntityAdapter* _adp = static_cast<EntityAdapter*>(adp);
			if(entity && _adp->getEntity()){
				entity->attack(_adp->getEntity());
				return true;
			}
		}catch(const exception& err){
			return false;
		}
		
	}
	return false;
}

bool EntityAdapter::die(){
	if(entity){
		entity->die();
		return true;
	}
	return false;
}

bool EntityAdapter::canTravelSea(){
	if(entity){
		return entity->canTravelSea();
	}
	return false;
}
bool EntityAdapter::canTravelLand(){
	if(entity){
		return entity->canTravelLand();
	}
	return false;
}


void EntityAdapter::onHandle(SignalEvent* e){
	try{
		ActionResult* res = dynamic_cast<ActionResult*>(e);

		if(res->isFinished()){
			if(res->isSuccess()){
				//do stuff when its fulfilled success

			}else{
				//do stuff when its failed
			}
		}else{
			//do stuff while it processes
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

void EntityAdapter::onFulFilled(SignalEvent* e){
	try{
		ActionResult* res = dynamic_cast<ActionResult*>(e);

		if(res->isSuccess()){
			//do stuff on success
			string* _action = res->getData("action");
			if(_action){
				action(*_action);
			}
		}else{
			//do stuff on fail
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

#endif