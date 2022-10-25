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

#include "../SignalHandler/SignalHandler.h"

using namespace std;

class ActionResultState{
public:
	ActionResultState(string state, bool lockable);
	~ActionResultState();

	string getStatus();
	virtual void lock() = 0;
	virtual void unlock() = 0;

	bool isLockable;
protected:
	bool stateLock;
private:
	string status;
};

class ActionRequest;

class ActionResult{
friend class ActionRequest;
public:
	ActionResult(ActionRequest* req);
	ActionResult(ActionRequest* req, ActionResultState* newState);
	ActionResult(ActionResult& other);
	~ActionResult();

	ActionResult* clone();
	ActionRequest* getOriginalRequest();

	string* getData(string key);
	
	string getResultStatus();
	SignalHandler* getStatusHandler();
	bool isSuccess();
protected:
	void changeResultState(ActionResultState* newState);
	void setData(string key, string val);
	void setDataMap(map<string,string> newData);

	void onHandle(SignalEvent* e);
	
	bool success;
	map<string,string> resultData;
	ActionRequest* request;

	SignalHandler* statusHandler;
	ActionResultState* resultState;
};

class ActionRequest{
public:
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func);
	ActionRequest(int _wait, function<void(SignalEvent*)> func);
	ActionRequest(ActionRequest& other);
	~ActionRequest();

	ActionRequest* clone();
	virtual void process();
	virtual void process(map<string,string> newData);
	SignalEvent* handle();
	string setData(string key, string val);
	string getData(string key);

	ActionResult* getResult();
	
	int getWaitCount();
	int getCurrWaitCount();

	string getID();
protected:
	int waitCount;
	int currWaitCount;

	ActionResult* result;
	
	map<string,string> requestData;
	FunctionHandler* actionHandler;
private:
	string id;
};

class ActionManager{
public:
	ActionManager();
	~ActionManager();

	void processCurrRequest();
	void pushRequest(ActionRequest* req);
	ActionRequest* removeRequest(string id);

	ActionRequest* getRequestByID(string id);
	ActionResult* getResultByID(string id);

	ActionRequest* getCurrentRequest();

	bool hasAnyRequests();
protected:
	void pushToQueue(ActionRequest* req);
	ActionRequest* popFromQueue();

	ObjectSignalBus<ActionResultState*>* actionEventBus;
	map<string, ActionRequest*> requests;
	// map<string, ActionRequest*> results;
	queue<ActionRequest*> actionQueue;
};

///All states

class ARS_Processing: public ActionResultState{
public:
	ARS_Processing();
	~ARS_Processing();

	void lock();
	void unlock();
};

class ARS_Success: public ActionResultState{
public:
	ARS_Success();
	~ARS_Success();

	void lock();
	void unlock();
};

class ARS_Pending: public ActionResultState{
public:
	ARS_Pending();
	~ARS_Pending();

	void lock();
	void unlock();
};

class ARS_Failed: public ActionResultState{
public:
	ARS_Failed();
	~ARS_Failed();

	void lock();
	void unlock();
};


#endif