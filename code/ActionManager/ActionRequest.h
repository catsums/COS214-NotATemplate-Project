#ifndef ACTIONREQUEST_H
#define ACTIONREQUEST_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>

#include <functional>

#include "../SignalHandler/SignalHandler.h"

#include "ActionResult.h"

using namespace std;

enum ARS{
	PENDING,
	PROCESSING,
	FULFILLED
};

class ActionRequest{
	friend class ActionManager;
public:
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func);
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func, function<void(SignalEvent*)> proc);
	ActionRequest(int _wait, function<void(SignalEvent*)> func);
	ActionRequest(int _wait, function<void(SignalEvent*)> func, function<void(SignalEvent*)> proc);
	ActionRequest(ActionRequest& other);
	~ActionRequest();

	ActionRequest* clone();
	ActionResult* process(ActionResult* oldRes);
	virtual void onStateChange(SignalEvent* res);
	
	virtual void handle(ActionResult* res);

	string* setData(string key, string val);
	void setDataMap(map<string,string> newData);
	string* getData(string key);

	void changeStatus(ARS newState);	
	int getWaitCount(){
		return waitCount;
	}
	int getStartCount(){
		return startCount;
	}

	SignalHandler* getActionHandler(){
		return actionHandler;
	}
	SignalHandler* getProcessHandler(){
		return processHandler;
	}

	string getID(){
		return id;
	}

	string getStatusAsString(){
		return ActionRequest::statusToString(getStatus());
	}

	ARS getStatus(){
		return status;
	}

	static string statusToString(ARS status){
		switch(status){
			case (ARS::PENDING): return "PENDING";
			case (ARS::PROCESSING): return "PROCESSING";
			case (ARS::FULFILLED): return "FULFILLED";
			default: return "UNKNOWN";
		}
	}

	bool isWaiting(){
		return (status != ARS::FULFILLED);
	}

	virtual void waitOnce(){
		waitCount--;
	}
protected:
	virtual void _process(SignalEvent* res);
	int waitCount;
	int startCount;

	ARS status;
	
	map<string,string> requestData;
	FunctionHandler* actionHandler;
	FunctionHandler* processHandler;
	// ActionResult* result;
private:
	string id;
};

#endif