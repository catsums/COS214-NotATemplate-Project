#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

#include "Country/Country.h"
#include "SignalHandler/SignalBus.h"

#include "ActionManager/ActionManager.h"

#include "War/War.h"
#include "myHelper.cpp"

using namespace std;

int getRandomInt(int a, int b){
	return myHelper::uniformDistribution<int>(a,b);
}

string getRandomString(int size){
	return myHelper::randomString(size);
}

class myContext{
public:
	string name;
	int hp = 10;
	int dmg = 2;

	FunctionHandler* handler;

	myContext(string n){
		name = n;
		handler = new FunctionHandler([this](SignalEvent* e){
			onHandle(e);
		});
	}
	~myContext(){
		delete handler;
		handler = NULL;
	}

	void onHandle(SignalEvent* _e){
		
	}

	bool takeDamage(int d){
		hp -= d;

		if(hp<=0){
			return true;
		}
		return false;
	}
};

class baseAdapter{
	string id;
	vector<string> types;
	SignalBus* signalBus;

	map<string, SignalHandler*> handlers;
	baseAdapter(){
		id = myHelper::randomString(8);
		types.push_back("OBJECT");
	}

	virtual void emit(string n){
		signalBus->emit(n);
	}
	virtual void subscribe(string n, SignalHandler* h){
		signalBus->subscribe(n, h);
	}
	virtual void unsubscribe(string n, SignalHandler* h){
		signalBus->unsubscribe(n, h);
	}
	virtual void onHandle(SignalEvent* e) = 0;
	virtual void onFulFilled(SignalEvent* e) = 0;

	void addHandler(string n, SignalHandler* handler){
		if(handlers.count(n)<=0){
			handlers[n] = handler;
		}
	}
	SignalHandler* removeHandler(string n){
		SignalHandler* handler = NULL;
		if(handlers.count(n)>0){
			handler = handlers[n];
			handlers.erase(n);
		}
		return handler;
	}

	bool isType(string n){
		for(int i=0; i<(int)types.size();i++){
			string _type = types[i];
			if(_type == n) return true;
		}
		return false;
	}
};

class AdapterManager{
public:
	map<string,vector<baseAdapter>> list;

	AdapterManager(){

	}
};

class myAdapter: public baseAdapter{
public:
	int reqCount = 1;
	vector<ActionRequest*> requests;

	FunctionHandler* handler;

	myContext* ctx;
	myAdapter(myContext* _ctx){
		ctx = _ctx;

		handlers["requestHandle"] = new FunctionHandler([this](SignalEvent* e){
			onHandle(e);
		});
		handlers["requestFulFill"] = new FunctionHandler([this](SignalEvent* e){
			onFulFilled(e);
		});
	}
	~myAdapter(){
		ctx = NULL;
		delete handler;
		handler = NULL;
	}

	string getName(){
		if(ctx){
			return ctx->name;
		}
		return "";
	}

	void checkRequests(){

		for(int i=0; i<(int)requests.size();i++){
			ActionRequest* req = requests[i];
			if(req->getWaitCount()<=0){
				requests.erase(requests.begin()+i);
				i--;
				reqCount++;
			}
		}
	}

	ActionRequest* createRequest(map<string,string>& data, ActionManager* actionManager){
		if(reqCount<=0) return NULL;
		ActionRequest* req = new ActionRequest(getRandomInt(0,4),data,[this](SignalEvent* e){
			onFulFilled(e);
		},[this](SignalEvent* e){
			onHandle(e);
		});

		actionManager->pushRequest(req);

		reqCount--;
		requests.push_back(req);

		return req;
	}

	void onProcess(ActionResult* res){
		
	}

	void onFulFilled(SignalEvent* e){

	}

	bool attack(string id, string type){
		return true;
	}

	void onFulFilled(SignalEvent* e){
		try{
			ActionResult* res = dynamic_cast<ActionResult*>(e);

			if(res->isSuccess()){
				string* target = res->getData("fix");
				if(target){
					cout<<"Fix Target: "<<*target<<endl;
				}else{
					cout<<"No Fixable Target"<<endl;
				}
			}else{
				// cout<<" "<<res->getRequestID()<<" FAIL"<<endl;
			}
		}catch(const bad_cast& err){
			cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
		}
		
	}

	void onHandle(SignalEvent* e){
		try{
			ActionResult* res = dynamic_cast<ActionResult*>(e);

			if(res->isFinished()){
				if(res->isSuccess()){
					cout<<" "<<res->getRequestID()<<" SUCCESS OK"<<endl;
				}else{
					cout<<" "<<res->getRequestID()<<" FAIL"<<endl;
				}
			}else{
				onProcess(res);
			}
		}catch(const bad_cast& err){
			cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
		}
		checkRequests();

	}
};



class StepManager{
public:
	ActionManager actionManager;
	vector<myAdapter*> arr;
	int step = 0;
	int maxStep = 9;
	StepManager(){
		
	}
	~StepManager(){

	}
	void start(){
		mainLoop();
	}
	void mainLoop(){
		while(step<maxStep){
			cout<<"----Step "<<step<<"----"<<endl;
			cout<<"------------------------"<<endl;

			///try to get requests
			cout<<">>> Pushing requests"<<endl;
			checkEnvironment();
			cout<<"------------------------"<<endl;
			///run all requests
			cout<<">>> Running requests"<<endl;
			while(!actionManager.isEmptyQueue()){
				actionManager.handleCurrRequest();
			}
			//get queue for next step
			actionManager.placeNextQueue();
			///increment step count
			step++;
		}
	}
	void checkEnvironment(){
		for(int i=0; i<(int)arr.size();i++){
			myAdapter* ctx = arr[i];
			// cout<<">> Checking Context["<<ctx->name<<"]..."<<endl;
			int coin = getRandomInt(0,1);
			if(coin==0 && ctx->reqCount>0){
				map<string,string> reqData;
				reqData["fix"] = ctx->getName();
				ActionRequest* req = ctx->createRequest(reqData, &actionManager);
				cout<<ctx->name<<" opened a request: "<<req->getID()<<" waiting "<<req->getStartCount()<<endl;
			}
		}
	}
};

void managerTest()
{
	StepManager manager;

	myAdapter* adp1 = new myAdapter(
		new myContext("cake")
	);
	myAdapter* adp2 = new myAdapter(
		new myContext("tart")
	);
	myAdapter* adp3 = new myAdapter(
		new myContext("cookie")
	);

	manager.arr.push_back(adp1);
	manager.arr.push_back(adp2);
	manager.arr.push_back(adp3);

	manager.start();

}

int main(){
	managerTest();

	return 0;
}