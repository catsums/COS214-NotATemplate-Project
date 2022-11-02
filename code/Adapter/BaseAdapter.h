#ifndef BASEADAPTER_H
#define BASEADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include <functional>

#include "../SignalHandler/SignalBus.h"
#include "../ActionManager/ActionManager.h"
#include "../myHelper.cpp"

using namespace std;

class BaseAdapter{
public:
	BaseAdapter(){
		id = myHelper::randomString(8);
		types.push_back("OBJECT");

		handlers["requestHandle"] = new FunctionHandler([this](SignalEvent* e){
			onHandle(e);
		});
		handlers["requestFulFill"] = new FunctionHandler([this](SignalEvent* e){
			onFulFilled(e);
		});
	}
	~BaseAdapter(){
		delete signalBus;
		signalBus = NULL;
	}

	virtual ActionRequest* createRequest(SignalHandler* handler, int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, [this](SignalEvent* e){
			onFulFilled(e);
		},[this](SignalEvent* e){
			onHandle(e);
		});

		return req;
	}
	virtual ActionRequest* createRequest(map<string,string> data, SignalHandler* handler, int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, data, [this](SignalEvent* e){
			onFulFilled(e);
		},[this](SignalEvent* e){
			onHandle(e);
		});

		return req;
	}
	virtual void action(string actionName) = 0;

	virtual void onHandle(SignalEvent* e) = 0;
	virtual void onFulFilled(SignalEvent* e) = 0;

	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}

	virtual void emit(string n){
		signalBus->emit(n);
	}
	virtual void subscribe(string n, SignalHandler* h){
		signalBus->subscribe(n, h);
	}
	virtual void unsubscribe(string n, SignalHandler* h){
		signalBus->unsubscribe(n, h);
	}

	string getType(){
		return (types.back());
	}
	vector<string> getTypes(){
		return types;
	}
	bool isType(string n){
		for(int i=0; i<(int)types.size();i++){
			string _type = types[i];
			if(_type == n) return true;
		}
		return false;
	}

	string getID(){
		return id;
	}

	vector<string> getAllTypes(){
		return types;
	}

protected:

	string id;
	vector<string> types;
	map<string, SignalHandler*> handlers;
	map<string, ActionRequest*> requests;

	SignalBus* signalBus;

};

#endif