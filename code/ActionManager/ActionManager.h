/** @file ActionManager.h
 *  @brief Processing the action requests made by the war engine and managing them
 *
 *  
 */

#ifndef ACTIONMANAGER_H
#define ACTIONMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#include <utility>
#include <initializer_list>

#include <functional>

#include "../SignalHandler/SignalBus.h"

#include "ActionRequest.h"
#include "ActionResult.h"

using namespace std;

/**	
*	ActionManager is a Command bus that makes use of ActionRequests as the commands and invokes them after a certain period of time
*	and returns a Result to the Signalhandlers it stores based on the id of that request, along with the result data
*/

class ActionManager:public SignalBus{
public:
	///creates the action manager object
	/** Constructor for action manager 
    */
	ActionManager();

	///destrcutor
	~ActionManager();

	/**
	*	@param emits a signal based on the id of the request, which will send the current result to the completion handler for the request object
	*/
	virtual void emit(string n);

	/**
	* @param processes a request and returns a result object which may be temporary for further processing or the final result for completion
	*/
	ActionResult* processRequest(ActionRequest* req);
	//handles the current request on the top of the queue as it pops and returns it back in the queue for next step
	bool handleCurrRequest();
	
	/** push request to the bottom of the queue of other requests and the request lists based on id
	*	@param also creates a pending result for the request to process it
	*/
	void pushRequest(ActionRequest* req);
	
	/**
	*	@param removes a request from the queue and the list based on the id
	*/
	ActionRequest* removeRequest(string id);
	
	/**
	*	@param removes a result from the result list by request id
	*/
	ActionResult* removeResult(string id);
	
	/**
	*	@param gets a request in the list by id
	*/
	ActionRequest* getRequestByID(string id);
	
	/**
	*	@param gets a result object in the list by id
	*/
	ActionResult* getResultByID(string id);
	
	/**get current request at the top of the queue
	*/
	ActionRequest* getCurrentRequest();
	
	/**replaces the current queue with the queue of next requests
	*/
	void placeNextQueue();
	//checks if there are any requests in the queue or the next queue
	bool hasAnyRequests();
	//checks if the current queue is empty
	bool isEmptyQueue();
	//gets the number of requests in the current queue
	int getQueueSize(){
		return (int) actionQueue.size();
	}
	//gets number of requests in the next queue
	int getNextQueueSize(){
		return (int) nextQueue.size();
	}
protected:
	// virtual void sendEvent(string n, SignalEvent* event);
	virtual SignalEvent* createSignalEvent(string n); /**<creates a Actionresult based on an id and returns it as an Actionresult*/
	
	void pushToQueue(ActionRequest* req);/**<pushes a request to the current queue*/
	
	void pushToNext(ActionRequest* req); /**<pushes a request to the next queue*/
	
	ActionRequest* popFromQueue();/**<pops a request from the current queue*/

	map<string, ActionRequest*> requests;	/**<list of all requests sorted by id*/
	map<string, ActionResult*> results;	/**list of all results sorted by request id*/
	// queue<ActionRequest*> actionQueue;
	queue<ActionRequest*> actionQueue;	/**<queue for actionRequests*/
	queue<ActionRequest*> nextQueue;	/**next queue for actionRequests*/
};


#endif