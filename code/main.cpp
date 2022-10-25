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
	int reqCount = 5;
	vector<ActionRequest*> requests;
	myContext(string n){
		name = n;
	}
	~myContext(){

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
		ActionRequest* req = new ActionRequest(getRandomInt(1,4),data,[this](SignalEvent* e){
			onHandle(e);
		});

		actionManager->pushRequest(req);

		reqCount--;
		requests.push_back(req);

		return req;
	}

	void onProcess(ActionResult* res){
		cout<<" Status: "<<res->getStatusAsString()<<" WaitTime: "<<res->getOriginalRequest()->getWaitCount()<<endl;
		res->setData("fish", name);
	}

	void onHandle(SignalEvent* e){
		try{
			ActionResult* res = dynamic_cast<ActionResult*>(e);

			if(res->isFinished()){
				if(res->isSuccess()){
					cout<<"SUCCESS OK"<<endl;

					cout<<"> Fishes ID:"<<*(res->getData("fish"))<<endl;
				}else{
					cout<<"FAIL"<<endl;
				}
			}else{
				// cout<<"Still Processing..."<<endl;
				onProcess(res);
			}
		}catch(const bad_cast& err){
			cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
		}

	}
};

class StepManager{
public:
	ActionManager actionManager;
	vector<myContext*> arr;
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

			/////////////	\	//run all requests
			cout<<">>> Running requests"<<endl;
			while(!actionManager.isEmptyQueue()){
				actionManager.handleCurrRequest();
			}
			// cout<<"Queue size - "<<actionManager.getQueueSize()<<endl;
			// cout<<"Next size - "<<actionManager.getNextQueueSize()<<endl;

			actionManager.placeNextQueue();

			// cout<<"Queue size - "<<actionManager.getQueueSize()<<endl;
			// cout<<"Next size - "<<actionManager.getNextQueueSize()<<endl;

			////////////try to get requests
			cout<<">>> Pushing requests"<<endl;
			checkEnvironment();

			// cout<<"Queue size - "<<actionManager.getQueueSize()<<endl;
			// cout<<"Next size - "<<actionManager.getNextQueueSize()<<endl;

			
			step++;
		}
	}
	void checkEnvironment(){
		for(int i=0; i<(int)arr.size();i++){
			myContext* ctx = arr[i];
			// cout<<">> Checking Context["<<ctx->name<<"]..."<<endl;
			int coin = getRandomInt(0,1);
			if(coin==0){
				cout<<ctx->name<<" opened a request"<<endl;
				map<string,string> reqData;
				reqData["fish"] = getRandomString(8);
				ctx->createRequest(reqData, &actionManager);
			}
		}
	}
};

void managerTest()
{
	StepManager manager;

	manager.arr.push_back(new myContext("carp"));
	manager.arr.push_back(new myContext("hake"));
	manager.arr.push_back(new myContext("jellyfish"));

	manager.start();

}

int main(){
	managerTest();

	return 0;
}