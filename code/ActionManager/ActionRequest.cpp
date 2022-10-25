#ifndef ACTIONREQUEST_CPP
#define ACTIONREQUEST_CPP

#include <random>

#include "ActionRequest.h"
#include "../myHelper.cpp"

using namespace std;

// static int getRandomInt(int a, int b){
//     int max, min;
//     if(a>b){
//         max = a; min = b;
//     }else{
//         max = b; min = a;
//     }
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_real_distribution<double> distr(min, max);

//     return (int) distr(gen);
// }
// static string randomString(int len = 9) {
//     const char alphanum[] =
//         "0123456789"
//         "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
//         "abcdefghijklmnopqrstuvwxyz";
//     int stringLen = sizeof(alphanum) - 1;

//     string str;
//     for (int i = 0; i < len; i++) {
//         int rnd = getRandomInt(0, stringLen);
//         str += alphanum[rnd % stringLen];
//     }
//     return str;
// }

ActionRequest::ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func){
	id = myHelper::randomString(8);

	waitCount = _wait;
	currWaitCount = _wait;
	requestData = _data;
	actionHandler = new FunctionHandler(func);

	// result = new ActionResult(getID(), this);
}
ActionRequest::ActionRequest(int _wait, function<void(SignalEvent*)> func){
	id = myHelper::randomString(8);

	waitCount = _wait;
	currWaitCount = _wait;
	actionHandler = new FunctionHandler(func);

	// result = new ActionResult(getID(), this);
}
ActionRequest::ActionRequest(ActionRequest& other){
	id = myHelper::randomString(8);

	waitCount = other.waitCount;
	currWaitCount = other.waitCount;

	requestData = other.requestData;
	actionHandler = new FunctionHandler(*(other.actionHandler));

	// result = new ActionResult(getID(), this);
}
ActionRequest::~ActionRequest(){
	actionHandler = NULL;
	// result = NULL;
}
string ActionRequest::getID(){
	return id;
}
string* ActionRequest::getData(string key){
	if(requestData.count(key)>0){
		return &(requestData[key]);
	}
	return NULL;
}
string* ActionRequest::setData(string key, string val){
	string* _val = NULL;
	if(requestData.count(key)>0){
		_val = &(requestData[key]);
	}
	requestData[key] = val;
	return _val;
}
void ActionRequest::setDataMap(map<string,string> newData){
	requestData = newData;
}

// void ActionRequest::handle(){
	
// }

SignalHandler* ActionRequest::getActionHandler(){
	return actionHandler;
}

// void ActionRequest::_process(SignalEvent* e){

// 	ActionResult* newResult = static_cast<ActionResult*>(e);
	
// 	if(result->getStatus() == ARS::SUCCESS || result->getStatus() == ARS::FAIL){
// 		//do nothing
// 	}
// 	currWaitCount--;
// 	if(result->getStatus() == ARS::STARTED){
// 		newResult->changeResultState(ARS::PENDING);
// 	}
// 	if(result->getStatus() == ARS::PENDING && currWaitCount<=0){
// 		newResult->changeResultState(ARS::PROCESSING);
// 	}
	
// }
// ActionResult* ActionRequest::process(){
// 	SignalEvent* e = result->clone();
// 	ActionResult* newResult = static_cast<ActionResult*>(e);
	
// 	_process(e);
// 	return newResult;
// }
// ActionResult* ActionRequest::process(map<string,string> newData){
// 	SignalEvent* e = result->clone();
// 	ActionResult* newResult = static_cast<ActionResult*>(e);
	
// 	for(map<string,string>::iterator it=newData.begin(); it!=newData.end();++it){
// 		string k =  it->first;

// 		newResult->setData(k, newData[k]);
// 	}

// 	_process(e);
// 	return newResult;
// }

// ActionResult* ActionRequest::getResult(){
// 	if(!result){
// 		result = new ActionResult(getID(),this);
// 		result->setDataMap(this->requestData);
// 	}

// 	return result;
// }

int ActionRequest::getStartCount(){
	return waitCount;
}
int ActionRequest::getWaitCount(){
	return currWaitCount;
}

ActionRequest* ActionRequest::clone(){
	return new ActionRequest(*this);
}

#endif