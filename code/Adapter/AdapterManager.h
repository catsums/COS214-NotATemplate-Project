#ifndef ADAPTERMANAGER_H
#define ADAPTERMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "BaseAdapter.h"

/*	
	Manager that allows other adapters to find other adapters using simply the id and type and perform actions on them implicitly
	This acts as a mediator between adapters that are not able to interact with each other direcrly
*/

class AdapterManager{
public:
	//creates the Manager with empty lists
	AdapterManager();
	~AdapterManager();

	//adds an adapter to the manager and puts it in the lists based on its type
	bool addAdapter(BaseAdapter* adp);
	//removes an adapter from a list based on the type and id
	BaseAdapter* removeAdapter(string type, string id);
	//removes the adapter from all the lists it is present in
	void removeAdapter(BaseAdapter* adp);
	//get a specific adapter based on its type and id
	BaseAdapter* getAdapter(string type, string id);

	vector<BaseAdapter*> getAdapters(string type){
		vector<BaseAdapter*> adps;
		if(lists.count(type)>0){
			map<string,BaseAdapter*>* list = lists[type];
			for(auto adp:(*list)){
				adps.push_back(adp.second);
			}
			
		}
		return adps;
	}
protected:
	//has many lists all split by type and each list has a list of adapters sorted by id
	map<string, map<string, BaseAdapter*>*> lists;
};

#endif