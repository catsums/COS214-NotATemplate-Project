#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "BaseAdapter.h"
#include "AdapterManager.h"

using namespace std;

class Adapter: public BaseAdapter{
public:
	Adapter(AdapterManager* mng);
	~Adapter();

	virtual void action(string actionName);

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

protected:
	// void* adaptee; //just a wacky silly pointer to store anything
	AdapterManager* manager;
};

#endif