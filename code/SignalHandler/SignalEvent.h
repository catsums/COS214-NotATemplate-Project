/** @file SignalEvent.h
*	@brief 	SignalEvent carries data and the name of the emitted event from the SignalBus to be parsed and can be extended by any other class
*	
*   This is used to share states dynamically in the observer pattern
*/


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
	/**
	*	@param string name
	*/
	SignalEvent(string n); /**<creates signal event with the event name*/
	~SignalEvent(); /**<Destructor*/
	
	string getEventName() const; /**<get event name*/
	
	virtual SignalEvent* clone() = 0; /**<creates a copy of the signal event*/
protected:
	SignalEvent(); /**<Constructor*/
	string name; /**<String name*/
};

/**	
*	Default Event that can be used to send signals that do not need to carry additional data
*/

class SignalDefaultEvent: public SignalEvent{
public:
	/**
	*	@param string name 
	*/
	SignalDefaultEvent(string n); /**<creates the event object*/
	
	/**
	*	@param signal default event reference
	*/
	SignalDefaultEvent(SignalDefaultEvent& other); /**<copy constructor*/
	~SignalDefaultEvent(); /**<Destructor*/
	
	SignalEvent* clone(); /**<clone the signal event*/

	time_t callTime;	/**<records the step time it gets called*/
	int callCount;		/**<records the amount of times the event was called*/
};

#endif