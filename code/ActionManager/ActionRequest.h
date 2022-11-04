/** @file ActionRequest.h
 *  @brief Processing the action requests made by the war engine
 *
 *  
 */


#ifndef ACTIONREQUEST_H
#define ACTIONREQUEST_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#include <utility>

#include <functional>

#include "../SignalHandler/SignalHandler.h"

#include "ActionResult.h"

using namespace std;

/** ACTION REQUEST STATE
*	Enum to show state of the Request, showing whether it is waiting to process, processing or finished processing
*/

enum ARS{
	PENDING,
	PROCESSING,
	FULFILLED
};

/** Request for action that has handlers to process and invoke a request based on a certain function
*	Request will create a result as it processes and update the result data based on the process function
*	and the request data as an input
*/

class ActionRequest{

	/** This is a class called ActionManager in this class where
	*	all the requests are processed.	
	*/
	friend class ActionManager; 
public:
	///create a request with a number of steps to wait, input data, processing function and function to handle when it finishes
	/** Action request function when it does not finish
	*	@param int variable that holds a number of steps 
	*	@param input data that is held by map
	*	@param processing function 
	*/
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func);

	/** Action request function once it is done 
	*	@param int variable that holds a number of steps 
	*	@param input data that is held by map
	*	@param processing function 
	*	@param function that handles everthing when it is finished 
	*/
	ActionRequest(int _wait, map<string,string> _data, function<void(SignalEvent*)> func, function<void(SignalEvent*)> proc);
	ActionRequest(int _wait, function<void(SignalEvent*)> func);
	ActionRequest(int _wait, function<void(SignalEvent*)> func, function<void(SignalEvent*)> proc);

	///copy constructor for action request to clone request
	ActionRequest(ActionRequest& other);
	/** Default constructor. Does something.
    */
	~ActionRequest();


	///clones request
	ActionRequest* clone();

	///processes a result to create a new result
	/**
	*	@param action result pointer that points to the value of the old results 
	*/
	ActionResult* process(ActionResult* oldRes);

	///handles result when state changes
	/**
	*	@param single event pointer that points to the result once it has changed  
	*/
	virtual void onStateChange(SignalEvent* res);

	///handles result when it completes
	/**
	*	@param action result pointer pointing to the final result 
	*/
	virtual void handle(ActionResult* res);

	///sets data for request input based on a key
	/**
	*	@param key passed in which will determine the request value
	*	@param string value 
	*/
	string* setData(string key, string val);

	/**
	*	@param sets all data for request as a map
	*/
	void setDataMap(map<string,string> newData);
	///gets all data for request as a map
	map<string,string> getDataMap();
	
	/**
	*	@param gets data for request based on a key
	*/
	string* getData(string key);

	/**
	*	@param changes status of request
	*/
	void changeStatus(ARS newState);
	///get number of steps to wait for request	
	int getWaitCount(){
		return waitCount;
	}
	///get number of steps request was meant to wait entirely
	int getStartCount(){
		return startCount;
	}
	///get the handler for action on completion
	SignalHandler* getActionHandler(){
		return actionHandler;
	}
	///get the handler for processing result
	SignalHandler* getProcessHandler(){
		return processHandler;
	}
	///get id of request
	string getID(){
		return id;
	}
	///get status of request as a string
	string getStatusAsString(){
		return ActionRequest::statusToString(getStatus());
	}
	///get status of request as an ARS
	ARS getStatus(){
		return status;
	}

	/** When this function is called it will return the status at that given time
	*	@param gets a string version of an ARS
	*/
	static string statusToString(ARS status){
		switch(status){
			case (ARS::PENDING): return "PENDING";
			case (ARS::PROCESSING): return "PROCESSING";
			case (ARS::FULFILLED): return "FULFILLED";
			default: return "UNKNOWN";
		}
	}
	///checks if the request has not been fulfilled
	bool isWaiting(){
		return (status != ARS::FULFILLED);
	}
	///virtual function for a request to wait once as it processes
	virtual void waitOnce(){
		waitCount--;
	}
protected:

	virtual void _process(SignalEvent* res); /**<internal processor for request for a specific result*/
	int waitCount;	/**<number of steps to wait until exeecution*/
	int startCount;	/**<number of steps to wait from the beginning*/

	ARS status;	/**<status of request*/
	
	map<string,string> requestData;	/**<data of request*/
	FunctionHandler* actionHandler;	/**<signalhandler for handling completion*/
	FunctionHandler* processHandler;	/**<signalhandler for handling processing*/
private:
	string id;	/**<id of request that is auto generated*/
};

#endif