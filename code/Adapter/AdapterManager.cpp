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
	string type = adp->getType();
	string id = adp->getID();
	if(!lists.count(type)){
		lists[type] = new map<string,BaseAdapter*>();
	}
	map<string, BaseAdapter*>* _list = lists[type];
	if(_list->count(id)>0){
		return false;
	}
	(*_list)[id] = adp;
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