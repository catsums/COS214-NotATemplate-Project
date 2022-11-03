#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

// #include "Country/Country.h"
#include "SignalHandler/SignalBus.h"

#include "ActionManager/ActionManager.h"

#include "NewEntity/SoldierFactory.h"
#include "NewEntity/MedicFactory.h"
#include "NewEntity/Tank.h"
#include "NewEntity/Truck.h"

#include "War/War.h"
#include "myHelper.cpp"

using namespace std;

int getRandomInt(int a, int b){
	return myHelper::uniformDistribution<int>(a,b);
}

string getRandomString(int size){
	return myHelper::randomString(size);
}

// int main(){

// 	string nationA = "Japan";
// 	string nationB = "Korea";

// 	Citizen* ctn1 = new Citizen(20, nationA);
// 	Citizen* ctn2 = new Citizen(25, nationA);

// 	SoldierFactory* barracks = new SoldierFactory();

// 	Soldier* s1 = barracks->createSoldier(ctn2, 16);

// 	Tank* tank = new Tank(50,nationB,100);
// 	Truck* truck = new Truck(40,nationA,100);

// 	truck->carryPassenger(ctn1);
// 	truck->carryPassenger(s1);

// 	cout<<"s1 alive:"<<s1->isAlive()<<endl;
// 	tank->attack(truck);
// 	tank->attack(truck);
// 	tank->attack(truck);
// 	cout<<"s1 alive:"<<s1->isAlive()<<endl;

// 	return 0;
// }

// class myContext{
// public:
// 	string name;
// 	int hp = 10;
// 	int dmg = 2;

// 	FunctionHandler* handler;

// 	myContext(string n){
// 		name = n;
// 		handler = new FunctionHandler([this](SignalEvent* e){
// 			onHandle(e);
// 		});
// 	}
// 	~myContext(){
// 		delete handler;
// 		handler = NULL;
// 	}

// 	void onHandle(SignalEvent* _e){
		
// 	}

// 	bool takeDamage(int d){
// 		hp -= d;

// 		if(hp<=0){
// 			return true;
// 		}
// 		return false;
// 	}
// };

// class baseAdapter{
// public:
// 	string id;
// 	vector<string> types;
// 	SignalBus* signalBus;

// 	map<string, SignalHandler*> handlers;
// 	baseAdapter(){
// 		id = myHelper::randomString(8);
// 		types.push_back("OBJECT");
// 	}
// 	string getID(){
// 		return id;
// 	}

// 	virtual void emit(string n){
// 		signalBus->emit(n);
// 	}
// 	virtual void subscribe(string n, SignalHandler* h){
// 		signalBus->subscribe(n, h);
// 	}
// 	virtual void unsubscribe(string n, SignalHandler* h){
// 		signalBus->unsubscribe(n, h);
// 	}
// 	// virtual void onHandle(SignalEvent* e) = 0;
// 	// virtual void onFulFilled(SignalEvent* e) = 0;

// 	void addHandler(string n, SignalHandler* handler){
// 		if(handlers.count(n)<=0){
// 			handlers[n] = handler;
// 		}
// 	}
// 	SignalHandler* removeHandler(string n){
// 		SignalHandler* handler = NULL;
// 		if(handlers.count(n)>0){
// 			handler = handlers[n];
// 			handlers.erase(n);
// 		}
// 		return handler;
// 	}

// 	bool isType(string n){
// 		for(int i=0; i<(int)types.size();i++){
// 			string _type = types[i];
// 			if(_type == n) return true;
// 		}
// 		return false;
// 	}
// 	string getType(){
// 		return (types.back());
// 	}
// };

// class AdapterManager{
// public:
// 	map<string, map<string, baseAdapter*>*> lists;

// 	AdapterManager(){

// 	}
// 	~AdapterManager(){

// 	}

// 	void addAdapter(baseAdapter* adp){
// 		string type = adp->getType();
// 		string id = adp->getID();
// 		if(!lists.count(type)){
// 			lists[type] = new map<string,baseAdapter*>();
// 		}
// 		map<string, baseAdapter*>* _list = lists[type];

// 		(*_list)[id] = adp;

// 	}

// 	baseAdapter* getAdapter(string type, string id){

// 		if(lists.count(type)>0){
// 			map<string, baseAdapter*>* _list = lists[type];
// 			if(_list->count(id)>0){
// 				baseAdapter* adp = (*_list)[id];
// 				return adp;
// 			}
// 		}
// 		return NULL;
// 	}
// };

// class myAdapter: public baseAdapter{
// public:
// 	int reqCount = 1;
// 	vector<ActionRequest*> requests;

// 	FunctionHandler* handler;

// 	AdapterManager* manager;

// 	myContext* ctx;
// 	myAdapter(myContext* _ctx, AdapterManager* mng){
// 		ctx = _ctx;
// 		manager = mng;

// 		handlers["requestHandle"] = new FunctionHandler([this](SignalEvent* e){
// 			onHandle(e);
// 		});
// 		handlers["requestFulFill"] = new FunctionHandler([this](SignalEvent* e){
// 			onFulFilled(e);
// 		});

// 		if(manager){
// 			manager->addAdapter(this);
// 		}
// 	}
// 	~myAdapter(){
// 		ctx = NULL;
// 		manager = NULL;
// 		delete handler;
// 		handler = NULL;
// 	}

// 	string getName(){
// 		if(ctx){
// 			return ctx->name;
// 		}
// 		return "[NULL]";
// 	}

// 	void checkRequests(){

// 		for(int i=0; i<(int)requests.size();i++){
// 			ActionRequest* req = requests[i];
// 			if(req->getWaitCount()<=0){
// 				requests.erase(requests.begin()+i);
// 				i--;
// 				reqCount++;
// 			}
// 		}
// 	}

// 	ActionRequest* createRequest(map<string,string>& data, ActionManager* actionManager){
// 		if(reqCount<=0) return NULL;
// 		ActionRequest* req = new ActionRequest(getRandomInt(0,4),data,[this](SignalEvent* e){
// 			onFulFilled(e);
// 		},[this](SignalEvent* e){
// 			onHandle(e);
// 		});

// 		actionManager->pushRequest(req);

// 		reqCount--;
// 		requests.push_back(req);

// 		return req;
// 	}

// 	void onProcess(ActionResult* res){
		
// 	}

// 	bool attack(string id, string type){
// 		return true;
// 	}

// 	void onFulFilled(SignalEvent* e){
// 		try{
// 			ActionResult* res = dynamic_cast<ActionResult*>(e);

// 			if(res->isSuccess()){
// 				string* target = res->getData("fix");
// 				if(target){
// 					cout<<"Fix Target: "<<*target<<endl;
// 				}else{
// 					cout<<"No Fixable Target"<<endl;
// 				}
// 			}else{
// 				// cout<<" "<<res->getRequestID()<<" FAIL"<<endl;
// 			}
// 		}catch(const bad_cast& err){
// 			cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
// 		}
		
// 	}

// 	void onHandle(SignalEvent* e){
// 		try{
// 			ActionResult* res = dynamic_cast<ActionResult*>(e);

// 			if(res->isFinished()){
// 				if(res->isSuccess()){
// 					cout<<" "<<res->getRequestID()<<" SUCCESS OK"<<endl;
// 				}else{
// 					cout<<" "<<res->getRequestID()<<" FAIL"<<endl;
// 				}
// 			}else{
// 				onProcess(res);
// 			}
// 		}catch(const bad_cast& err){
// 			cout<<"Error trying to cast SignalEvent to ActionEvent"<<endl;
// 		}
// 		checkRequests();

// 	}
// };



// class StepManager{
// public:
// 	ActionManager actionManager;
// 	AdapterManager adpManager;
// 	int step = 0;
// 	int maxStep = 9;
// 	StepManager(){
		
// 	}
// 	~StepManager(){

// 	}
// 	void start(){
// 		mainLoop();
// 	}
// 	void mainLoop(){
// 		while(step<maxStep){
// 			cout<<"----Step "<<step<<"----"<<endl;
// 			cout<<"------------------------"<<endl;

// 			///try to get requests
// 			cout<<">>> Pushing requests"<<endl;
// 			checkEnvironment();
// 			cout<<"------------------------"<<endl;
// 			///run all requests
// 			cout<<">>> Running requests"<<endl;
// 			while(!actionManager.isEmptyQueue()){
// 				actionManager.handleCurrRequest();
// 			}
// 			//get queue for next step
// 			actionManager.placeNextQueue();
// 			///increment step count
// 			step++;
// 		}
// 	}
// 	void checkEnvironment(){
// 		for(int i=0; i<(int)arr.size();i++){
// 			Adapter* adp = arr[i];
// 			// cout<<">> Checking Context["<<ctx->name<<"]..."<<endl;
// 			int coin = getRandomInt(0,1);
// 			if(coin==0 && ctx->reqCount>0){
// 				map<string,string> reqData;
// 				reqData["fix"] = ctx->getName();
// 				ActionRequest* req = ctx->createRequest(reqData, &actionManager);
// 				cout<<ctx->getName()<<" opened a request: "<<req->getID()<<" waiting "<<req->getStartCount()<<endl;
// 			}
// 		}
// 	}
// };

void managerTest()
{

	War* war = new War();

	Country* countryA = new Country("Ares");
	Country* countryB = new Country("Bethlen");
	Country* countryC = new Country("Catia");


	war->addCountry(countryA, 0);
	war->addCountry(countryB, 0);
	war->addCountry(countryC, 1);

	war->changePhase(new PhaseWar());

	war->warMap->setSize(3,3);
	war->warMap->genStandardMap();

	countryA->addZone(war->warMap->getZone(0,0));
	countryA->addZone(war->warMap->getZone(0,1));
	countryB->addZone(war->warMap->getZone(1,0));
	countryC->addZone(war->warMap->getZone(2,2));

	int citNum = 5;

	Position mapSize = war->warMap->getMapSize();
	

	for(int i=0;i<2;i++){
		vector<Country*>* side = war->getCountriesOnSide(i);
		if(side){
			cout<<"-----SIDE "<<i<<"------"<<endl;
			for(int j=0;j<side->size();j++){
				Country* country = side->at(j);
				if(country){
					for(int i=0;i<citNum;i++){
						Citizen* ctn = new Citizen(100);
						country->addCitizen(ctn);

						for(int r=0; r<mapSize.x;r++){
							for(int c=0; c<mapSize.y;c++){
								Zone* zone = war->warMap->getZone(r,c);
								if(zone && country->hasZone(zone)){
									if(myHelper::coinFlip() == 0){
										war->warMap->moveEntity(zone, ctn);
									}
								}
							}
						}
					}
				}

				cout<<country->printInfo()<<endl;
			}
		}
	}

	

}

int main(){
	managerTest();
	// cout<<"Coin "<<myHelper::coinFlip()<<endl;

	return 0;
}