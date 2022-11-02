#ifndef OBJECTSIGNALEVENT_H
#define OBJECTSIGNALEVENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <ctime>

#include <functional>

#include "SignalEvent.h"

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


#endif