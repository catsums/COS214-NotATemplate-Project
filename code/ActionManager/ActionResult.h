/** @file ActionResult.h
 *  @brief Processing the action requests made and keeping them in the action result file. 
 *
 *  
 */

#ifndef ACTIONRESULT_H
#define ACTIONRESULT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <ctime>
#include <utility>

#include <functional>

#include "../SignalHandler/SignalEvent.h"
// #include "ActionRequest.h"

using namespace std;

/**
*	Result of Request while or after it has been processed with all the data meant to be returned after a certain time
*/

class ActionResult: public SignalEvent{
	/** This is a class called ActionRequest in this class where
	*	all the requests are made.
	*/
	friend class ActionRequest;

	/** This is a class called ActionManager in this class where
	*	all the requests are processed.	
	*/
	friend class ActionManager;
public:
	///creates the result based on the request id, success and result data
	/**
	* @param string variable that takes in the ID of the action result 
	*/
	ActionResult(string id);
	/**
	*	@param string variable that takes in the ID of the action result 
	*	@param bool determining the failure/success of the passing through of a result  
	*/
	ActionResult(string id, bool success);

	/**
	*	@param string variable that takes in the ID of the action result 
	*	@param bool determining the failure/success of the passing through of a result
	*	@param data relating to the  map  
	*/
	ActionResult(string id, bool success, map<string,string> _data);
	ActionResult(ActionResult& other);

	///Destructor
	~ActionResult();

	///creates a clone of the result since it is a signal event
	SignalEvent* clone();
	
	
	/**get data based on a key or returns null if nonexistent
	*	@param string variable of the key passed through 
	*/
	string* getData(string key);

	
	/**set data based on a key and value
	*	@param string variable of the key passed through 
	*	@param the key passed in has a corresponding string value	
	*/
	string* setData(string key, string val);
	
	/**
	*	@param set data using a hashmap of strings 
	*/
	map<string,string> setDataMap(map<string,string> newData);
	///get all data as a hashmap
	map<string,string> getDataMap();
	///returns the id of the result, which is the id of the original request
	string getRequestID(){
		return id;
	}
	
	///check if request was finished
	bool isFinished();
	///check if request was a success
	bool isSuccess();
protected:
	
	/**
	*	@param resolves the result by finishing the request and setting its succession		
	*/
	void resolve(bool s);

	bool success;	/**<request succession*/
	bool finished;	/**<request completion*/
	map<string,string> resultData; /**data of the result*/
	string id;	/**<id of the original request*/

};

#endif