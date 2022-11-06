/** @file AdapterManager.h
*	@brief An example of how we incorporated the adapter pattern into our war simulator 
*/

#ifndef ADAPTERMANAGER_H
#define ADAPTERMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "BaseAdapter.h"

/**	
*	Manager that allows other adapters to find other adapters using simply the id and type and perform actions on them implicitly
*	This acts as a mediator between adapters that are not able to interact with each other direcrly
*/

class AdapterManager{
public:
	///creates the Manager with empty lists
	///Constructor
	AdapterManager();

	///Destructor
	~AdapterManager();

	/** adds an adapter to the manager and puts it in the lists based on its type
	*	@param BaseAdapter pointer 	
	*/
	bool addAdapter(BaseAdapter* adp);
	/** removes an adapter from a list based on the type and id
	*	@param string variable that represents the type 
	*	@param string variable that represents the id	
	*/
	BaseAdapter* removeAdapter(string type, string id);
	/** removes the adapter from all the lists it is present in
	*	@param BaseAdapter pointer 	
	*/
	void removeAdapter(BaseAdapter* adp);
	/**get a specific adapter based on its type and id
	*	@param string variable that represents the type 
	*	@param string variable that represents the id	
	*/
	BaseAdapter* getAdapter(string type, string id);
protected:
	map<string, map<string, BaseAdapter*>*> lists; /**<has many lists all split by type and each list has a list of adapters sorted by id*/
};

#endif