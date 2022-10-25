#ifndef ACTIONMANAGER_CPP
#define ACTIONMANAGER_CPP


#include "ActionManager.h"
#include "../myHelper.cpp"

using namespace std;

///ActionResultState

ActionResultState::ActionResultState(string state, bool lockable){
	status = state;
	isLockable = lockable;
}
ActionResultState::~ActionResultState(){
	
}
string ActionResultState::getStatus(){
	return status;
}
///ActionResult
ActionResult::ActionResult(ActionRequest* req){
	request = req;
	resultState = new ARS_Pending();

	success = false;
	statusHandler = new FunctionHandler([this](SignalEvent* e){
		onStatusHandle(e);
	});

	dataHandler = new FunctionHandler([this](SignalEvent* e){
		onDataHandle(e);
	});

	dataHandler = new FunctionHandler([this](SignalEvent* e){
		onSuccessHandle(e);
	});
}
ActionResult::ActionResult(ActionRequest* req, ActionResultState* newState){
	request = req;
	resultState = newState;

	success = false;
	statusHandler = new FunctionHandler([this](SignalEvent* e){
		onStatusHandle(e);
	});

	dataHandler = new FunctionHandler([this](SignalEvent* e){
		onDataHandle(e);
	});

	dataHandler = new FunctionHandler([this](SignalEvent* e){
		onSuccessHandle(e);
	});
}
ActionResult::ActionResult(ActionResult& other){
	resultData = other.data;
	request = other.req;
	resultState = other.resultState;

	success = other.success;
	statusHandler = new FunctionHandler(other.statusHandler);
}
ActionResult::~ActionResult(){
	resultState = NULL;
	statusHandler = NULL;
	request = NULL;
}

void ActionResult::changeResultState(ActionResultState* newState){
	resultState = newState;
}
string ActionResult::getResultStatus(){
	return resultState->getStatus();
}
SignalHandler* ActionResult::getStatusHandler(){
	return statusHandler;
}
ActionRequest* ActionResult::getOriginalRequest(){
	return request;
}
bool ActionResult::isSuccess(){
	return success;
}

void ActionResult::onStatusHandle(SignalEvent* _e){
	ObjectSignalEvent<ActionResultState>* e = static_cast<ObjectSignalEvent<ActionResultState>*>(_e);

	ActionResultState* newState = e->getData();

	changeResultState(newState);

	string eventName = e->getEventName();

	if(eventName == "success"){
		success = true;
	}
}

///ActionRequest
ActionRequest::ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func){
	id = myHelper::randomString(8);

	waitCount = _wait;
	currWaitCount = _wait;
	requestData = _data;
	actionHandler = new FunctionHandler(func);

	result = new ActionResult(_data, this);
}
ActionRequest::ActionRequest(int _wait, function<void(SignalEvent*)> func){
	id = myHelper::randomString(8);

	waitCount = _wait;
	currWaitCount = _wait;
	actionHandler = new FunctionHandler(func);

	// result = new ActionResult(requestData, this);
}
ActionRequest::ActionRequest(ActionRequest& other){
	id = myHelper::randomString(8);

	waitCount = other.waitCount;
	currWaitCount = other.waitCount;

	requestData = other.requestData;
	actionHandler = new FunctionHandler(*(other.actionHandler));

	// result = new ActionResult(_data, this);
}
ActionRequest::~ActionRequest(){
	actionHandler = NULL;
	result = NULL;
}
string ActionRequest::getID(){
	return id;
}
string* ActionRequest::getData(string key){
	if(requestData.count(key)>0){
		return &requestData[key];
	}
	return NULL;
}
void ActionRequest::setData(string key, string val){
	requestData[key] = val;
}
void ActionRequest::setDataMap(map<string,string> newData){
	requestData = newData;
}

SignalEvent* ActionRequest::handle(){
	SignalEvent* e = new ObjectSignalEvent<map<string,string>>("request", requestData);

	actionHandler->handle(e);

	return e;
}

void ActionRequest::process(){
	currWaitCount--;
}
void ActionRequest::process(map<string,string> newData){
	
	for(map<string,string>::iterator it=newData.begin(); it!=newData.end();++it){
		string k =  it->first;

		requestData[k] = newData[k];
	}

	currWaitCount--;
}

ActionResult* ActionResult::getResult(){
	if(!result){
		result = new ActionResult(this);
		result->setDataMap(this->requestData);
	}

	return result;
}

int ActionRequest::getWaitCount(){
	return waitCount;
}
int ActionRequest::getCurrWaitCount(){
	return currWaitCount;
}

ActionRequest* ActionRequest::clone(){
	return new ActionRequest(*this);
}


///ActionManager
ActionManager::ActionManager(){
	actionEventBus = new ObjectSignalBus<ActionResultState*>();

}
ActionManager::~ActionManager(){
	actionEventBus = NULL;
}

void ActionManager::processCurrRequest(){
	ActionRequest* req = popFromQueue();
	if(req){
		ActionResult* res = req->getResult();

		req->process();
		if(req->getWaitCount()<=0){
			SignalEvent* event = req->handle();
		}
	}
}

ActionRequest* ActionManager::getCurrentRequest(){
	ActionRequest* req = NULL;
	if(!queue.empty()){
		req = queue.front();
	}
	return req;
}

void ActionManager::pushRequest(ActionRequest* req){
	if(req==NULL) return;
	if(requests.count(req->getID())<=0){
		requests[req->getID()] = req;
		ActionResult* res = req->getResult();
		SignalHandler* handler = res->getStatusHandler();
		pushToQueue(req);

		actionEventBus->subscribe("success", handler);
		actionEventBus->subscribe("pending", handler);
		actionEventBus->subscribe("failed", handler);
		actionEventBus->subscribe("processing", handler);
	}
}

void ActionManager::pushToQueue(ActionRequest* req){
	actionQueue.push(req);
}

ActionRequest* ActionManager::popFromQueue(){
	ActionRequest* req = NULL;
	if(!queue.empty()){
		req = queue.pop();
	}
	return req;
}

ActionRequest* ActionManager::getRequestByID(string id){
	if(requests.count(id)>0){
		return requests[id];
	}
	return NULL;
}
ActionRequest* ActionManager::getResultByID(string id){
	if(requests.count(id)>0){
		return requests[id]->getResult();
	}
	return NULL;
}

#endif