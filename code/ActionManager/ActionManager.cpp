#ifndef ACTIONMANAGER_CPP
#define ACTIONMANAGER_CPP

#include <random>

#include "ActionManager.h"

// #include "ActionRequest.h"
// #include "ActionResult.h"

using namespace std;

static int getRandomInt(int a, int b){
    int max, min;
    if(a>b){
        max = a; min = b;
    }else{
        max = b; min = a;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(min, max);

    return (int) distr(gen);
}
static string randomString(int len = 9) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLen = sizeof(alphanum) - 1;

    string str;
    for (int i = 0; i < len; i++) {
        int rnd = getRandomInt(0, stringLen);
        str += alphanum[rnd % stringLen];
    }
    return str;
}


///ActionResult


///ActionRequest



///ActionManager
ActionManager::ActionManager(){
	

}
ActionManager::~ActionManager(){

}

bool ActionManager::hasAnyRequests(){
	return (!results.empty());
}

bool ActionManager::isEmptyQueue(){
	return actionQueue.empty();
}
bool ActionManager::handleCurrRequest(){
	ActionResult* res = popFromQueue();
	ActionRequest* req = res->getOriginalRequest();
	if(req){
		// ActionResult* preRes = req->getResult();
		res = results[req->getID()];

		if(res->getOriginalRequest() != req){
			res->changeResultState(ARS::FAIL);
		}

		if(!res->isFinished()){
			ARS status = res->getStatus();
			if(req->getWaitCount() <= 0){
				res->finished = true;
				if(status==ARS::PROCESSING){
					res->changeResultState(ARS::SUCCESS);
				}else if(status==ARS::PENDING){
					res->changeResultState(ARS::FAIL);
				}else if(status==ARS::STARTED){
					res->finished = false;
				}
			}else if(status==ARS::FAIL || status==ARS::SUCCESS){
				res->finished = true;
			}
			
			emit(req->getID());
			ActionResult* newRes = processRequest(req);
			results[req->getID()] = newRes;
		}
		
		if(!res->isFinished()){
			pushToNext(res);
		}else{
			removeRequest(req->getID());
		}
		return true;
	}
	return false;
}

ActionResult* ActionManager::processRequest(ActionRequest* req){
	ActionResult* res = getResultByID(req->getID());

	SignalEvent* e = res->clone();

	ActionResult* newRes = static_cast<ActionResult*>(e);

	if(res->getStatus() == ARS::SUCCESS || res->getStatus() == ARS::FAIL){
		//do nothing
	}
	req = newRes->getOriginalRequest();
	req->currWaitCount--;
	if(res->getStatus() == ARS::STARTED){
		newRes->changeResultState(ARS::PENDING);
	}else if(res->getStatus() == ARS::PENDING && req->getWaitCount() <= 0){
		newRes->changeResultState(ARS::PROCESSING);
	}else if(res->getStatus() == ARS::PROCESSING && req->getWaitCount() < 0){
		newRes->changeResultState(ARS::FAIL);
	}

	return newRes;
}

ActionRequest* ActionManager::getCurrentRequest(){
	ActionRequest* req = NULL;
	if(!actionQueue.empty()){
		ActionResult* res = actionQueue.front();
		if(res){
			return res->getOriginalRequest();
		}
	}
	return req;
}

void ActionManager::pushRequest(ActionRequest* req){
	if(req==NULL) return;
	if(results.count(req->getID())<=0){
		// requests[req->getID()] = req;
		ActionResult* res = new ActionResult(req);
		results[req->getID()] = res;

		subscribe(req->getID(), req->getActionHandler());

		pushToQueue(res);
	}
}
ActionResult* ActionManager::removeRequest(string id){
	ActionResult* res = NULL;
	if(results.count(id)>0){
		res = results[id];
		if(res){
			results.erase(id);
		}
	}
	return res;
}

void ActionManager::pushToQueue(ActionResult* res){
	actionQueue.push(res);
}

void ActionManager::pushToNext(ActionResult* res){
	nextQueue.push(res);
}

ActionResult* ActionManager::popFromQueue(){
	ActionResult* res = NULL;
	if(!actionQueue.empty()){
		res = actionQueue.front();
		actionQueue.pop();
	}
	return res;
}

ActionRequest* ActionManager::getRequestByID(string id){
	ActionResult* res = getResultByID(id);
	if(res){
		return res->getOriginalRequest();
	}
	return NULL;
}
ActionResult* ActionManager::getResultByID(string id){
	if(results.count(id)>0){
		return results[id];
	}
	return NULL;
}

void ActionManager::emit(string n){
	if(hasSignal(n)){
		SignalEvent* event = createSignalEvent(n);
		sendEvent(n, event);
	}
}

SignalEvent* ActionManager::createSignalEvent(string n){
	ActionResult* event = NULL;
	if(results.count(n)>0){
		event = results[n];
	}

	return event;
}

void ActionManager::placeNextQueue(){
	actionQueue = nextQueue;
	nextQueue = *(new queue<ActionResult*>);
}

#endif