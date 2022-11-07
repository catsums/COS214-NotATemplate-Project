/** @file ObjectSignalBus.h
*	@brief SignalBus that handles all its events using ObjectSignalEvents, therefore can emit data in the event as well
*	
*/
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
	
	ObjectSignalBus(); /**<creates a signal bus*/
	~ObjectSignalBus(); /**<Destructor*/
	
	/**
	*	@param string name
	*/
	virtual void emit(string n); /**<emit the signal with NULL data*/

	
	/**
	*	@param string name
	*	@param data
	*/	
	virtual void emit(string n, T* _data); /**emits the signal with data passed into it*/

protected:
	
	/**
	*	@param string name
	*/
	virtual SignalEvent* createSignalEvent(string n); /**<creates a signalevent of type ObjectSignalEvent but has NULL data*/

	/**
	*	@param string name
	*	@param data
	*/	
	virtual SignalEvent* createSignalEvent(string n, T* _data); /**<creates a signalevent of type ObjectSignalEvent with specific data*/
};

#endif