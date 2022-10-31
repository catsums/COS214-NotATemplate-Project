#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

#include "SignalEvent.h"

using namespace std;

class SignalHandler{
public:
	SignalHandler();
	~SignalHandler();

	string getID() const;
	virtual void handle(SignalEvent* event) = 0;

private:
	string id;
};

class FunctionHandler: public SignalHandler{
public:
	FunctionHandler(function<void(SignalEvent*)> newFunc);
	FunctionHandler(FunctionHandler& other);
	~FunctionHandler();
protected:
	virtual void handle(SignalEvent* event);
	function<void(SignalEvent*)> func;
};

#endif