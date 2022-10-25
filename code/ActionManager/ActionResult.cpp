#ifndef ACTIONRESULT_CPP
#define ACTIONRESULT_CPP

#include <random>

#include "ActionResult.h"

using namespace std;

ActionResult::ActionResult(ActionRequest* req){
	if(req){
		name = req->getID();
	}
	request = req;
	resultState = ARS::STARTED;

	finished = false;
}
ActionResult::ActionResult(ActionRequest* req, ARS newState){
	if(req){
		name = req->getID();
	}
	request = req;
	resultState = newState;

	finished = false;
}
ActionResult::ActionResult(ActionResult& other){
	name = other.name;
	request = other.request;
	resultState = other.resultState;
	resultData = other.resultData;

	finished = other.finished;
}
ActionResult::~ActionResult(){
	request = NULL;
}

SignalEvent* ActionResult::clone(){
	return new ActionResult(*this);
}

void ActionResult::changeResultState(ARS newState){
	resultState = newState;
}
ARS ActionResult::getStatus(){
	return resultState;
}
ActionRequest* ActionResult::getOriginalRequest(){
	return request;
}
bool ActionResult::isFinished(){
	return finished;
}
bool ActionResult::isSuccess(){
	return (resultState == ARS::SUCCESS);
}

string* ActionResult::getData(string key){
	if(resultData.count(key)>0){
		return &(resultData[key]);
	}
	return NULL;
}
string* ActionResult::setData(string key, string val){
	string* _val = NULL;
	if(resultData.count(key)>0){
		_val = &(resultData[key]);
	}
	resultData[key] = val;
	return _val;
}

#endif