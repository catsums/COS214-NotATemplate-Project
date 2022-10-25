#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>

#include <functional>

#include "../SignalHandler/SignalBus.h"

#include "ActionRequest.h"
#include "ActionResult.h"

using namespace std;

class ActionManager:public SignalBus{
public:
	ActionManager();
	~ActionManager();

	virtual void emit(string n);

	ActionResult* processRequest(ActionRequest* req);

	bool handleCurrRequest();
	void pushRequest(ActionRequest* req);
	ActionResult* removeRequest(string id);

	ActionRequest* getRequestByID(string id);
	ActionResult* getResultByID(string id);

	ActionRequest* getCurrentRequest();

	void placeNextQueue();

	bool hasAnyRequests();
	bool isEmptyQueue();

	int getQueueSize(){
		return (int) actionQueue.size();
	}
	int getNextQueueSize(){
		return (int) nextQueue.size();
	}
protected:
	// virtual void sendEvent(string n, SignalEvent* event);
	virtual SignalEvent* createSignalEvent(string n);

	void pushToQueue(ActionResult* res);
	void pushToNext(ActionResult* res);
	ActionResult* popFromQueue();

	// map<string, ActionRequest*> requests;
	map<string, ActionResult*> results;
	// queue<ActionRequest*> actionQueue;
	queue<ActionResult*> actionQueue;
	queue<ActionResult*> nextQueue;
};


#endif