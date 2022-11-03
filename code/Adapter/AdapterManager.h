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

	bool addAdapter(BaseAdapter* adp);
	BaseAdapter* removeAdapter(string type, string id);
	void removeAdapter(BaseAdapter* adp);
	BaseAdapter* getAdapter(string type, string id);
protected:
	map<string, map<string, BaseAdapter*>*> lists;
};

#endif