#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

using namespace std;

class SignalEvent{
public:
	SignalEvent(string n);
	~SignalEvent();
	string getEventName() const;

	virtual SignalEvent* clone() = 0;
protected:
	SignalEvent();
	string name;
};

class SignalDefaultEvent: public SignalEvent{
public:
	SignalDefaultEvent(string n);
	SignalDefaultEvent(SignalDefaultEvent& other);
	~SignalDefaultEvent();

	SignalEvent* clone();

	time_t callTime;
	int callCount;
};

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
	~FunctionHandler();
protected:
	virtual void handle(SignalEvent* event);
	function<void(SignalEvent*)> func;
};

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

template<class T>
class ObjectSignalEvent: public SignalEvent{
public:
	ObjectSignalEvent(string n, T* data);
	ObjectSignalEvent(ObjectSignalEvent& other);
	~ObjectSignalEvent();

	SignalEvent* clone();

	T* getData() const;
public:
	T* data;
};

template<class T>
class ObjectSignalBus: public SignalBus{
public:
	ObjectSignalBus();
	~ObjectSignalBus();

	virtual void emit(string n);
	virtual void emit(string n, T* _data);

protected:
	virtual SignalEvent* createSignalEvent(string n);
	virtual SignalEvent* createSignalEvent(string n, T* _data);
};

#endif