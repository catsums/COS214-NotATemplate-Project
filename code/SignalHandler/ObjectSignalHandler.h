/** @file ObjectSignalHandler.h
 *  
 */


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
	/** Parameter constructor
	*	@param string name
	*	@param data 
	*/
	ObjectSignalEvent(string n, T* data);

	/** Parameter constructor
	*	@param Reference of a object signal event
	*/
	ObjectSignalEvent(ObjectSignalEvent& other);

	///Destructor
	~ObjectSignalEvent();

	SignalEvent* clone(); /**<Signal event pointer which clones*/

	T* getData() const; /**<retrieves data*/
public:
	T* data; /**<holds data*/
};

template<class T>
class ObjectSignalBus: public SignalBus{
public:
	ObjectSignalBus(); /**<Constructor*/
	~ObjectSignalBus(); /**<Destructor*/

	/**
	*	@param string name 
	*/
	virtual void emit(string n); /**<emit function*/

	/**
	*	@param string name 
	*	@param data 
	*/
	virtual void emit(string n, T* _data); /**<emit function*/

protected:
	/**
	*	@param string name 
	*/
	virtual SignalEvent* createSignalEvent(string n); /**<signal event*/
	/**
	*	@param string name 
	*	@param data 
	*/
	virtual SignalEvent* createSignalEvent(string n, T* _data); /**<signal event with data*/
};

#endif