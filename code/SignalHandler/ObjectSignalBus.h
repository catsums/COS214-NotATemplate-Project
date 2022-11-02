#ifndef OBJECTSIGNALBUS_H
#define OBJECTSIGNALBUS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

#include "SignalBus.h"
#include "ObjectSignalEvent.h"

using namespace std;

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