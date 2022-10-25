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

using namespace std;

// class ActionResult;

class ActionRequest{
	friend class ActionManager;
public:
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func);
	ActionRequest(int _wait, function<void(SignalEvent*)> func);
	ActionRequest(ActionRequest& other);
	~ActionRequest();

	ActionRequest* clone();
	// virtual ActionResult* process();
	// virtual ActionResult* process(map<string,string> newData);
	// void handle();
	string* setData(string key, string val);
	void setDataMap(map<string,string> newData);
	string* getData(string key);

	// ActionResult* getResult();
	
	int getWaitCount();
	int getStartCount();

	SignalHandler* getActionHandler();

	string getID();
protected:
	// virtual void _process(SignalEvent* e);
	int waitCount;
	int currWaitCount;
	
	map<string,string> requestData;
	FunctionHandler* actionHandler;
	// ActionResult* result;
private:
	string id;
};

#endif