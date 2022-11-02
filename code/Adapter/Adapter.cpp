#ifndef ADAPTER_CPP
#define ADAPTER_CPP

#include "Adapter.h"

using namespace std;

Adapter::Adapter(AdapterManager* mng):BaseAdapter(){
	manager = mng;
}
Adapter::~Adapter(){
	manager = NULL;
}

void Adapter::onHandle(SignalEvent* e){
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

void Adapter::onFulFilled(SignalEvent* e){
	try{
		ActionResult* res = dynamic_cast<ActionResult*>(e);

		if(res->isSuccess()){
			//do stuff on success
		}else{
			//do stuff on fail
		}
	}catch(const bad_cast& err){
		cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
	}
}

#endif