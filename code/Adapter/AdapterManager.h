#ifndef ADAPTERMANAGER_H
#define ADAPTERMANAGER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "BaseAdapter.h"

class AdapterManager{
public:
	AdapterManager();
	~AdapterManager();

	void addAdapter(BaseAdapter* adp){
		string type = adp->getType();
		string id = adp->getID();
		if(!lists.count(type)){
			lists[type] = new map<string,BaseAdapter*>();
		}
		map<string, BaseAdapter*>* _list = lists[type];

		(*_list)[id] = adp;

	}
	BaseAdapter* getAdapter(string type, string id){

		if(lists.count(type)>0){
			map<string, BaseAdapter*>* _list = lists[type];
			if(_list->count(id)>0){
				BaseAdapter* adp = (*_list)[id];
				return adp;
			}
		}
		return NULL;
	}
protected:
	map<string, map<string, BaseAdapter*>*> lists;
};

#endif