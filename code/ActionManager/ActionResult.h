#ifndef ACTIONRESULT_H
#define ACTIONRESULT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>

#include <functional>

// #include "../SignalHandler/SignalEvent.h"
#include "ActionRequest.h"

using namespace std;

enum ARS{
	STARTED,
	PENDING,
	PROCESSING,
	SUCCESS,
	FAIL,
};

class ActionResult: public SignalEvent{
friend class ActionRequest;
friend class ActionManager;
public:
	ActionResult(ActionRequest* req);
	ActionResult(ActionRequest* req, ARS newState);
	ActionResult(ActionResult& other);
	~ActionResult();

	static string statusToString(ARS status){
		switch(status){
			case (ARS::STARTED): return "STARTED";
			case (ARS::PENDING): return "PENDING";
			case (ARS::PROCESSING): return "PROCESSING";
			case (ARS::SUCCESS): return "SUCCESS";
			case (ARS::FAIL): return "FAIL";
			default: return "UNKNOWN";
		}
	}

	SignalEvent* clone();
	ActionRequest* getOriginalRequest();
	
	void changeResultState(ARS newState);
	string* getData(string key);
	string* setData(string key, string val);
	void setDataMap(map<string,string> newData);

	ARS getStatus();

	string getStatusAsString(){
		return ActionResult::statusToString(getStatus());
	}
	
	// SignalHandler* getStatusHandler();
	bool isFinished();
	bool isSuccess();
protected:
	// void onHandle(SignalEvent* e);
	
	bool finished;
	map<string,string> resultData;
	ActionRequest* request;

	// SignalHandler* statusHandler;
	ARS resultState;
};

#endif