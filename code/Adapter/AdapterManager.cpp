#ifndef ADAPTERMANAGER_CPP
#define ADAPTERMANAGER_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "AdapterManager.h"

AdapterManager::AdapterManager(){

}
AdapterManager::~AdapterManager(){

}

bool AdapterManager::addAdapter(BaseAdapter* adp){
	// string type = adp->getType();
	vector<string> types = adp->getTypes();
	string id = adp->getID();
	for(int i=0; i<(int)types.size();i++){
		string type = types[i];
		if(!lists.count(type)){
			lists[type] = new map<string,BaseAdapter*>();
		}
		map<string, BaseAdapter*>* _list = lists[type];
		if(_list->count(id)>0){
			continue;
		}
		(*_list)[id] = adp;
	}
	
	return true;
}
BaseAdapter* AdapterManager::removeAdapter(string type, string id){
	BaseAdapter* adp = NULL;
	if(lists.count(type)>0){
		map<string, BaseAdapter*>* _list = lists[type];
		if(_list->count(id)>0){
			BaseAdapter* adp = (*_list)[id];
			_list->erase(id);
		}
	}
	return adp;
}
void AdapterManager::removeAdapter(BaseAdapter* adp){
	vector<string> types = adp->getTypes();
	string id = adp->getID();
	for(int i=0; i<(int)types.size();i++){
		removeAdapter(types[i], id);
	}
}
BaseAdapter* AdapterManager::getAdapter(string type, string id){
	if(lists.count(type)>0){
		map<string, BaseAdapter*>* _list = lists[type];
		if(_list->count(id)>0){
			BaseAdapter* adp = (*_list)[id];
			return adp;
		}
	}
	return NULL;
}

#endif