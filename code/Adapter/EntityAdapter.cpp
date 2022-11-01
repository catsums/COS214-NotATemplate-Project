#ifndef ENTITYADAPTER_CPP
#define ENTITYADAPTER_CPP

#include "EntityAdapter.h"

using namespace std;

EntityAdapter::EntityAdapter(Entity* ent, AdapterManager* mng):Adapter(mng){
	types.push_back("ENTITY");
	entity = ent;

	enti
}
EntityAdapter::~EntityAdapter(){
	entity = NULL;
}

void EntityAdapter::action(string actionName){

}

bool EntityAdapter::takeDamage(int dmg){
	if(entity){
		return entity->takeDamage(dmg);
	}
	return false;
}
bool EntityAdapter::heal(int amt){
	if(entity){
		return entity->heal(dmg);
	}
	return false;
}
bool EntityAdapter::heal(int amt){
	if(entity){
		entity->heal(dmg);
		return true;
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
bool EntityAdapter::attack(EntityAdapter* adp){
	if(entity && adp->getEntity()){
		entity->attack(adp->getEntity());
		return true;
	}
	return false;
}
bool EntityAdapter::attack(string id){
	BaseAdapter* adp = mng->getAdapter("ENTITY",id);
	if(adp){
		if(entity && adp->getEntity()){
			entity->attack(adp->getEntity());
			return true;
		}
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
			if(res->getData("action")){
				action(res->getData("action"));
			}
		}else{
			//do stuff on fail
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

#endif