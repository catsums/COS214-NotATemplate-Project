/** @file ObjectSignalEvent.h
*	@brief ObjectSignalEvent is an event that contains data of a specific type which can be passed on in a handler
*  
*/

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
	/** create signalevent with the corresponding data
	*	@param string name 
	*	@param data
	*/
	ObjectSignalEvent(string n, T* data);

	/** Parameter constructor
	*	@para bject signal even refrence 
	*/
	ObjectSignalEvent(ObjectSignalEvent& other);
	~ObjectSignalEvent();///Destructor
	
	SignalEvent* clone(); /**<create clone of signal event*/
	
	T* getData() const; /**<get the data passed on in the event*/
public:
	
	T* data; /**<data of the event as a pointer*/
};


#endif