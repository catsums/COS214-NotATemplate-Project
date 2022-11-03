#ifndef BASEADAPTER_H
#define BASEADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include <functional>

#include "../SignalHandler/SignalBus.h"
#include "../ActionManager/ActionManager.h"
#include "../myHelper.cpp"

using namespace std;

/*	
	Base Adapter is an abstract class used for being stored inside the Adapter manager 
	and holding all functionality to create and handle requests for objects in each turn
	This will wrap around a specific object in order to implement actions in the Command pattern
*/

class BaseAdapter{
public:
	/*Constructs a new BaseAdapter with unique id and two handlers*/
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
	//CreateRequest() functions creates an ActionRequest which will execute in a number of turns, process some data and fun a process handler
	//acts as a factory method for ActionRequests
	virtual ActionRequest* createRequest(int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, [this](SignalEvent* e){
			onFulFilled(e);
		},[this](SignalEvent* e){
			onHandle(e);
		});

		return req;
	}
	virtual ActionRequest* createRequest(map<string,string> data,int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, data, [this](SignalEvent* e){
			onFulFilled(e);
		},[this](SignalEvent* e){
			onHandle(e);
		});

		return req;
	}
	virtual ActionRequest* createRequest(function<void(SignalEvent*)> f, int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, [this](SignalEvent* e){
			onFulFilled(e);
		},f);

		return req;
	}
	virtual ActionRequest* createRequest(function<void(SignalEvent*)> f, map<string,string> data, int waitTime){
		ActionRequest* req = new ActionRequest(waitTime, data, [this](SignalEvent* e){
			onFulFilled(e);
		},f);

		return req;
	}
	//will use the result data to run a specific action in the adapter to affect the adaptee
	virtual void action(map<string,string> data) = 0;

	//default process function for handling the request whenever it changes state or while its still pending
	virtual void onHandle(SignalEvent* e) = 0;
	//default function to run when request is finished processing and will handle result data
	virtual void onFulFilled(SignalEvent* e) = 0;

	//adds a new signalhandler to the list of signalhandlers
	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	//removes a signalhandler based on the name added with it
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}

	//uses signalbus to emit a signal with the given name to listeners
	virtual void emit(string n){
		signalBus->emit(n);
	}
	//add a listener to the adapter's signal bus
	virtual void subscribe(string n, SignalHandler* h){
		signalBus->subscribe(n, h);
	}
	//remove a listener from the adapter's signal bus
	virtual void unsubscribe(string n, SignalHandler* h){
		signalBus->unsubscribe(n, h);
	}

	//get the current type of the object
	string getType(){
		return (types.back());
	}
	//get all types of the object
	vector<string> getTypes(){
		return types;
	}
	//check if the object is of a specific type
	bool isType(string n){
		for(int i=0; i<(int)types.size();i++){
			string _type = types[i];
			if(_type == n) return true;
		}
		return false;
	}
	//get the id of the object
	string getID(){
		return id;
	}
	//get all the types of the object
	vector<string> getAllTypes(){
		return types;
	}

protected:

	string id;	//unique id for compare
	vector<string> types;	//types to keep track of current type and related types
	map<string, SignalHandler*> handlers;	//list of signalhandlers sorted by id
	map<string, ActionRequest*> requests;	//list of active requests sorted by id

	SignalBus* signalBus;	//allows for other objects with signalhandlers to listen to/observe to adapter

};

#endif