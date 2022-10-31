#ifndef ENTITYADAPTER_CPP
#define ENTITYADAPTER_CPP

#include "EntityAdapter.h"

using namespace std;

EntityAdapter::EntityAdapter(AdapterManager* mng):Adapter(mng){
	types.push_back("ENTITY");
}
EntityAdapter::~EntityAdapter(){

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