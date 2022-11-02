#ifndef SIGNALBUS_H
#define SIGNALBUS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

#include "SignalHandler.h"

using namespace std;

class SignalBus{
public:
	SignalBus();
	~SignalBus();

	virtual void emit(string n);
	
	void subscribe(string n, SignalHandler* listener);
	void unsubscribe(string n, SignalHandler* listener);

	bool hasSignal(string n);
protected:
	map<string, vector<SignalHandler*>*> signals;
	virtual void sendEvent(string n, SignalEvent* event);
	virtual SignalEvent* createSignalEvent(string n);
};

#endif