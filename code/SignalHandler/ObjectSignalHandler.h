#ifndef OBJECTSIGNALHANDLER_H
#define OBJECTSIGNALHANDLER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

#include "SignalBus.h"

using namespace std;

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