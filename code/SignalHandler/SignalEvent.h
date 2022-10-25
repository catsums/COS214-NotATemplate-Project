#ifndef SIGNALEVENT_H
#define SIGNALEVENT_H

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

#endif