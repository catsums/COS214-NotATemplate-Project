#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "BaseAdapter.h"
#include "AdapterManager.h"

using namespace std;

class Adapter: public BaseAdapter{
public:
	Adapter();
	~Adapter();

	virtual void action(map<string,string> data) = 0;

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	virtual void setManager(AdapterManager* mng){
		manager = mng;
	}

protected:
	// void* adaptee; //just a wacky silly pointer to store anything
	AdapterManager* manager;
};

#endif