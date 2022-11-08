#ifndef ENTITYADAPTER_CPP
#define ENTITYADAPTER_CPP

#include "EntityAdapter.h"

using namespace std;

EntityAdapter::EntityAdapter(Entity* ent):Adapter(){
	types.push_back("ENTITY");
	entity = ent;
}
EntityAdapter::~EntityAdapter(){
	entity = NULL;
}

ActionRequest* EntityAdapter::requestAttack(string target){
	map<string, string> data = {
		{"action","attack"},
		{"target",target}
	};
	cout<<entity->getType()<<"-"<<entity->getID()<<" requested to attack."<<endl;
	return createRequest(data, 0);
}
ActionRequest* EntityAdapter::requestHeal(int amt){
	map<string, string> data = {
		{"action","heal"},
		{"amount",to_string(amt)}
	};
	cout<<entity->getType()<<"-"<<entity->getID()<<" requested to heal."<<endl;
	return createRequest(data, 0);
}
ActionRequest* EntityAdapter::requestTakeDamage(int amt){
	map<string, string> data = {
		{"action","takeDamage"},
		{"amount",to_string(amt)}
	};
	cout<<entity->getType()<<"-"<<entity->getID()<<" requested to takeDamage."<<endl;
	return createRequest(data, 0);
}
ActionRequest* EntityAdapter::requestTravel(Zone* zone){
	if(!zone) return NULL;
	Position pos = zone->getPosition();
	map<string, string> data = {
		{"action","travel"},
		{"x",to_string(pos.x)},
		{"y",to_string(pos.y)}
	};
	cout<<entity->getType()<<"-"<<entity->getID()<<" requested to travel."<<endl;
	return createRequest(data, 0);
}
ActionRequest* EntityAdapter::requestDeath(){
	map<string, string> data = {
		{"action","die"}
	};
	cout<<entity->getType()<<"-"<<entity->getID()<<" requested to go to heaven."<<endl;
	return createRequest(data, 0);
}

void EntityAdapter::action(map<string,string> data){
	if(data.count("action")>0){
		string _action = data["action"];

		if(_action == "attack"){
			if(data.count("target")){
				attack(data["target"]);
			}
		}
		if(_action == "heal"){
			if(data.count("amount")>0){
				int amt;
				istringstream iss(data["amount"]);
				iss >> amt;
				heal(amt);
			}
		}
		if(_action == "takeDamage"){
			if(data.count("amount")>0){
				int amt;
				istringstream iss(data["amount"]);
				iss >> amt;
				takeDamage(amt);
			}
		}
		if(_action == "travel"){
			if(data.count("x")>0 && data.count("y")>0){
				int x, y;
				istringstream issX(data["x"]);
				istringstream issY(data["y"]);
				issX >> x; issY >> y;
				travel(x,y);
			}
		}
		if(_action == "die"){
			die();
		}
	}
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
		cout<<entity->getType()<<"-"<<entity->getID()<<" is travelling to Pos "<<x<<","<<y<<endl;
		entity->travel(x,y);
		return true;
	}
	cout<<"Failed to travel to pos at "<<x<<","<<y<<endl;
	return false;
}
bool EntityAdapter::travelToZone(Zone* z){
	if(entity && z){
		if( z->isLand() && entity->canTravelLand() || !z->isLand() && entity->canTravelSea() ){
			cout<<entity->getType()<<"-"<<entity->getID()<<" is travelling to Zone "<<z->getX()<<","<<z->getY()<<endl;
			z->moveEntity(entity);
			return true;
		}
	}
	cout<<"Failed to travel to zone"<<endl;
	return false;
}
bool EntityAdapter::attack(EntityAdapter* adp){
	if(entity && adp->getEntity()){
		Entity* targ = adp->getEntity();
		cout<<entity->getType()<<"-"<<entity->getID()<<" is attacking "<<targ->getType()<<"-"<<targ->getID()<<endl;
		entity->attack(targ);
		return true;
	}
	cout<<"Failed to attack target at "<<id<<endl;
	return false;
}
bool EntityAdapter::attack(string id){
	BaseAdapter* adp = manager->getAdapter("ENTITY",id);
	if(adp){
		try{
			EntityAdapter* _adp = static_cast<EntityAdapter*>(adp);
			if(entity && _adp->getEntity()){
				Entity* targ = _adp->getEntity();
				cout<<entity->getType()<<"-"<<entity->getID()<<" is attacking "<<targ->getType()<<"-"<<targ->getID()<<endl;
				entity->attack(targ);
				return true;
			}
		}catch(const exception& err){
			cout<<"Failed to cast the adp"<<endl;
		}
		
	}
	cout<<"Failed to attack target at "<<id<<endl;
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
			cout<<res->getRequestID()<<" - Still processing request..."<<endl;
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

void EntityAdapter::onFulFilled(SignalEvent* e){
	try{
		ActionResult* res = dynamic_cast<ActionResult*>(e);

		if(res->isSuccess()){
			cout<<res->getRequestID()<<" - SUCCESS."<<endl;
			//do stuff on success
			map<string,string> _data = res->getDataMap();
			action(_data);
		}else{
			//do stuff on fail
			cout<<res->getRequestID()<<" - FAILED."<<endl;
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

#endif