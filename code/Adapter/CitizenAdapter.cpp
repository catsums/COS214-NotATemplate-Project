#ifndef CITIZENADAPTER_CPP
#define CITIZENADAPTER_CPP


#include "CitizenAdapter.h"

using namespace std;

CitizenAdapter::CitizenAdapter(Citizen* ent):EntityAdapter(ent){
	types.push_back("CITIZEN");
}
CitizenAdapter::~CitizenAdapter(){
	entity = NULL;
}

void CitizenAdapter::onHandle(SignalEvent* e){
	EntityAdapter::onHandle(e);
}
void CitizenAdapter::onFulFilled(SignalEvent* e){
	EntityAdapter::onFulFilled(e);
}

void CitizenAdapter::action(map<string,string> data){
	EntityAdapter::action(data);

	if(data.count("action")>0){
		string _action = data["action"];

		if(_action == "equip"){

		}
		if(_action == "unequip"){

		}
		if(_action == "useItem"){

		}
	}
}


#endif