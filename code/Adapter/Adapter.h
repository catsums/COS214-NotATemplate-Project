/** @file Adapter.h
*	@brief An example oh how we incorporated the adapter pattern into our war simulator 
*/


#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
#include <initializer_list>

#include "BaseAdapter.h"
#include "AdapterManager.h"

using namespace std;

class Adapter: public BaseAdapter{
public:
	/** Constructor
    */
	Adapter();

	///Destructor
	~Adapter();

	/** pure virtual function that determines the action that will take place on the map
	*	@param data passed through from the postion on the map	
	*/
	virtual void action(map<string,string> data) = 0;

	///on handle event
	virtual void onHandle(SignalEvent* e);

	///handle to handle the succession of an event
	virtual void onFulFilled(SignalEvent* e);

	///setter that checks if there is a manager present or not
	virtual void setManager(AdapterManager* mng){
		if(manager){
			manager->removeAdapter(this);
		}
		manager = mng;
		if(manager){
			manager->addAdapter(this);
		}
	}

protected:
	// void* adaptee; //just a wacky silly pointer to store anything
	AdapterManager* manager; /**<Pointer adapter manager */
};

#endif