#ifndef CITIZENADAPTER_CPP
#define CITIZENADAPTER_CPP


#include "CitizenAdapter.h"

using namespace std;

CitizenAdapter::CitizenAdapter(Citizen* ent, AdapterManager* mng)EntityAdapter(mng){
	types.push_back("CITIZEN");
	entity = ent;
}
CitizenAdapter::~CitizenAdapter(){
	entity = NULL;
}

CitizenAdapter::void onHandle(SignalEvent* e){

}
CitizenAdapter::void onFulFilled(SignalEvent* e){

}

	//Entity stuffs
CitizenAdapter::string getInfluence(){

}

CitizenAdapter::bool takeDamage(int dmg){

}
CitizenAdapter::bool travel(){

}
CitizenAdapter::bool attack(EntityAdapter* adp){

}
CitizenAdapter::bool attack(string id){

}

#endif