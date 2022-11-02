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

#include "../SignalHandler/SignalEvent.h"
// #include "ActionRequest.h"

using namespace std;

class ActionResult: public SignalEvent{
friend class ActionRequest;
friend class ActionManager;
public:
	ActionResult(string id);
	ActionResult(string id, bool success);
	ActionResult(string id, bool success, map<string,string> _data);
	ActionResult(ActionResult& other);
	~ActionResult();

	SignalEvent* clone();
	
	string* getData(string key);
	string* setData(string key, string val);
	map<string,string> setDataMap(map<string,string> newData);
	map<string,string> getDataMap();

	string getRequestID(){
		return id;
	}
	
	// SignalHandler* getStatusHandler();
	bool isFinished();
	bool isSuccess();
protected:
	// void onHandle(SignalEvent* e);
	void resolve(bool s);

	bool success;
	bool finished;
	map<string,string> resultData;
	string id;

	// SignalHandler* statusHandler;
};

#endif