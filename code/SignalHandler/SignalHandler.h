/** @file SignalHandler.h
*	@brief SignalHandler will run a certain function whenever the signal is emitted and received, which "handles" the signal and data passed through
*	This runs or handles the state change in the observer
*/


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
	
	SignalHandler(); /**<creates the signal handler with a unique id*/
	~SignalHandler(); /**<Destructor*/
	
	string getID() const; /**<gets the id of handler*/
	
	/**
	*	@param signal event pointer
	*/
	virtual void handle(SignalEvent* event) = 0; /**<function used to handler the event and its data*/

private:
	string id; /**<unique id variable */
};

/**
*	FunctionHandler is a signal handler will take a function as a paramter for contruction and use that to handle the signal instead
*/

class FunctionHandler: public SignalHandler{
public:

	FunctionHandler(function<void(SignalEvent*)> newFunc); /**<creates the signal handler with a function to store. Note that this is normally a function lambda*/
	
	FunctionHandler(FunctionHandler& other);/**<copy constructor for the handler*/
	~FunctionHandler(); /**<Destructor*/
protected:
	
	virtual void handle(SignalEvent* event); /**<function used to run the function contained to handle the event and its data*/
	
	function<void(SignalEvent*)> func; /**<variable used to store the function. Function is a void type that takes a signalEvent ptr as a parameter*/
};

#endif