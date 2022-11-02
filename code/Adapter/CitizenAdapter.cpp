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

	//Entity stuffs
// CitizenAdapter::string getInfluence(){

// }

// CitizenAdapter::bool takeDamage(int dmg){

// }
// CitizenAdapter::bool travel(){

// }
// CitizenAdapter::bool attack(EntityAdapter* adp){

// }
// CitizenAdapter::bool attack(string id){

// }

#endif