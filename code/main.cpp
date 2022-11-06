#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>
#include <sstream>

#include <functional>

// #include "Country/Country.h"
#include "SignalHandler/SignalBus.h"

#include "ActionManager/ActionManager.h"

#include "NewEntity/SoldierFactory.h"
#include "NewEntity/MedicFactory.h"
#include "NewEntity/Tank.h"
#include "NewEntity/Truck.h"

#include "War/War.h"
#include "War/WarPhases.h"

#include "Adapter/AdapterWrapper.h"

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



// class myEngine{
// public:
// 	War* war;
// 	StepManager(War* w){
// 		war = w;
// 	}
// 	~StepManager(){
// 		war = NULL;
// 	}
// 	void start(){
// 		mainLoop();
// 	}
// 	void mainLoop(){
// 		while(!hasEnded()){
// 			cout<<"----Step "<<war->getStepCount()<<"----"<<endl;
// 			cout<<"------------------------"<<endl;

// 			///try to get requests
// 			cout<<">>> Pushing requests"<<endl;
// 			war->handlePhase();
// 			cout<<"------------------------"<<endl;
// 			///run all requests
// 			cout<<">>> Running requests"<<endl;
// 			ActionManager* actionManager
// 			while(!actionManager->isEmptyQueue()){
// 				actionManager->handleCurrRequest();
// 			}
// 			//get queue for next step
// 			actionManager->placeNextQueue();
// 			///increment step count
// 			war->incrementStep();
// 		}
// 	}
// };

// void attackNearest(War* war, EntityAdapter* adp){
// 	Zone* currZone = war->warMap->getZone(adp->getPosition());
// 	Entity* currEnt = adp->getEntity();

// 	if(!currZone || !currEnt){
// 		cout<<"No entity in adapter..."<<endl;
// 		return;
// 	}else{
// 		cout<<"Running on ent-"<<currEnt->getID()<<endl;
// 		// cout<<"LETS GOOOOOO"<<endl;
// 	}

// 	Entity* enemyEnt = NULL;

// 	//check if zone contains any enemy
// 	vector<Entity*> entsInZone = currZone->getEntities();
// 	for(int i=0;i<(int)entsInZone.size();i++){
// 		Entity* ent = entsInZone[i];
// 		if(ent->getCountry() != currEnt->getCountry()){
// 			enemyEnt = ent;
// 			break;
// 		}
// 	}

// 	if(enemyEnt){
// 		cout<<"FOUND ENEMY TO ATTACK"<<endl;
// 		EntityAdapter* target = AdapterWrapper::getAdapter(enemyEnt);
// 		war->adapterManager->addAdapter(target);
// 		target->setManager(war->adapterManager);

// 		ActionRequest* req = adp->requestAttack(target->getID());
// 		war->actionManager->pushRequest(req);
// 	}else{
// 		//if theres no enemy, try to find enemy in each adjacent zone
// 		vector<Zone*> adjZones = war->warMap->getAdjacent(currZone);
// 		Zone* targetZone = NULL;

// 		enemyEnt = NULL;

// 		for(int i=0;i<(int)adjZones.size();i++){
// 			Zone* adjZone = adjZones[i];
// 			if(adjZone){
// 				cout<<"checking zone-("<<adjZone->getX()<<","<<adjZone->getY()<<")"<<endl;
// 			}else{
// 				cout<<"Zone is NULL"<<endl;
// 			}

// 			vector<Entity*> entsHere = adjZone->getEntities();
// 			for(int i=0;i<(int)entsHere.size();i++){
// 				Entity* ent = entsHere[i];
// 				if(ent){
// 					cout<<"checking if ent "<<ent->getID()<<" is same country"<<endl;
// 				}else{
// 					cout<<"ent is NULL"<<endl;
// 				}
// 				if(ent->getCountry() != currEnt->getCountry()){
// 					enemyEnt = ent;
// 					targetZone = adjZone;
// 					break;
// 				}
// 			}
// 			if(enemyEnt||targetZone){
// 				// targetZone = adjZone;
// 				break;
// 			}
// 		}
// 		if(targetZone){
// 			cout<<"FOUND ZONE TO TRAVEL TO"<<endl;
// 			ActionRequest* req = adp->requestTravel(targetZone);
// 			war->actionManager->pushRequest(req);
// 		}else{
// 			cout<<"No zone to travel to"<<endl;
// 		}
		
// 	}
// }

// void managerTest()
// {

// 	War* war = new War(new PhaseNeutral());

// 	Country* countryA = new Country("Ares");
// 	Country* countryB = new Country("Bethlen");
// 	Country* countryC = new Country("Catia");


// 	war->addCountry(countryA, 0);
// 	war->addCountry(countryB, 1);
// 	// war->addCountry(countryC, 1);

// 	war->warMap->setSize(1,2);
// 	war->warMap->genStandardMap();

// 	countryA->addZone(war->warMap->getZone(0,0));
// 	// countryA->addZone(war->warMap->getZone(0,1));
// 	countryB->addZone(war->warMap->getZone(1,0));
// 	// countryC->addZone(war->warMap->getZone(2,2));

// 	int citNum = 4;
// 	int vehNum = 2;

// 	Position mapSize = war->warMap->getMapSize();

// 	vector<Entity*> allEnts;

// 	Citizen* solA = new Soldier(20);
// 	countryA->addCitizen(solA);
// 	allEnts.push_back(solA);
// 	war->warMap->moveEntity(war->warMap->getZone(0,0), solA);

// 	Citizen* solB = new Soldier(20);
// 	countryA->addCitizen(solB);
// 	allEnts.push_back(solB);
// 	war->warMap->moveEntity(war->warMap->getZone(1,1), solB);

// 	Citizen* solC = new Soldier(20);
// 	countryA->addCitizen(solC);
// 	allEnts.push_back(solC);
// 	war->warMap->moveEntity(war->warMap->getZone(1,1), solC);
	
// 	Citizen* solD = new Soldier(20);
// 	countryA->addCitizen(solD);
// 	allEnts.push_back(solD);
// 	war->warMap->moveEntity(war->warMap->getZone(0,0), solD);

// 	Citizen* solE = new Soldier(20);
// 	countryB->addCitizen(solE);
// 	allEnts.push_back(solE);
// 	war->warMap->moveEntity(war->warMap->getZone(0,1), solE);
	
// 	Citizen* solF = new Soldier(20);
// 	countryB->addCitizen(solF);
// 	allEnts.push_back(solF);
// 	war->warMap->moveEntity(war->warMap->getZone(1,0), solF);

// 	Citizen* solG = new Soldier(20);
// 	countryB->addCitizen(solG);
// 	allEnts.push_back(solG);
// 	war->warMap->moveEntity(war->warMap->getZone(0,0), solG);

// 	Citizen* solH = new Soldier(20);
// 	countryB->addCitizen(solH);
// 	allEnts.push_back(solH);
// 	war->warMap->moveEntity(war->warMap->getZone(1,0), solH);

// 	// for(int i=0;i<2;i++){
// 	// 	vector<Country*>* side = war->getCountriesOnSide(i);
// 	// 	if(side){
// 	// 		// cout<<"-----SIDE "<<i<<"------"<<endl;
// 	// 		for(int j=0;j<side->size();j++){
// 	// 			Country* country = side->at(j);
// 	// 			if(country){
// 	// 				for(int i=0;i<citNum;i++){
// 	// 					Citizen* ctn = new Soldier(20);
// 	// 					country->addCitizen(ctn);
// 	// 					allEnts.push_back(ctn);

// 	// 					Zone* zone = war->warMap->getZone(
// 	// 						myHelper::randomInt(0,mapSize.x),
// 	// 						myHelper::randomInt(0,mapSize.y)
// 	// 					);
// 	// 					war->warMap->moveEntity(zone, ctn);
// 	// 				}
// 	// 			}

// 	// 			// cout<<country->printInfo()<<endl;
// 	// 		}
// 	// 	}
// 	// }
// 	for(int i=0;i<2;i++){
// 		vector<Country*>* side = war->getCountriesOnSide(i);
// 		if(side){
// 			// cout<<"-----SIDE "<<i<<"------"<<endl;
// 			for(int j=0;j<side->size();j++){
// 				Country* country = side->at(j);
// 				if(country){
// 					vector<Citizen*> citizens = country->getCitizens();
// 					for(int i=0;i<(int)citizens.size();i++){
// 						Citizen* ctn = citizens[i];
// 						EntityAdapter* adp = AdapterWrapper::getAdapter(ctn);
// 						war->adapterManager->addAdapter(adp);
// 						adp->setManager(war->adapterManager);

// 						attackNearest(war, adp);
// 					}
// 				}
// 			}
// 		}
// 	}

// 	for(int i=0;i<(int)allEnts.size();i++){
// 		cout<<allEnts[i]->printInfo()<<endl;
// 	}
	

// 	ActionManager* actionManager = war->actionManager;
// 	cout<<">> RUNNING REQUESTS..."<<endl;
// 	while(!actionManager->isEmptyQueue()){
// 		cout<<"next request..."<<endl;
// 		actionManager->handleCurrRequest();
// 	}
// 	//get queue for next step
// 	actionManager->placeNextQueue();
// 	///increment step count
// 	war->incrementStep();

// 	for(int i=0;i<(int)allEnts.size();i++){
// 		cout<<allEnts[i]->printInfo()<<endl;
// 	}

// }

ActionRequest* requestAttack(Entity* ent, Entity* target){
	
	ActionRequest* req = new ActionRequest(0, [=](SignalEvent* e){
		//on fulfilled
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(res){
				if(res->isFinished()){
					if(res->isSuccess()){
						cout<<res->getRequestID()<<" - SUCCESS"<<endl;
						cout<<ent->getType()<<"-"<<ent->getID()<<" is attacking "<<target->getType()<<"-"<<target->getID()<<"!"<<endl;
						ent->attack(target);
					}else{
						cout<<res->getRequestID()<<" - FAIL"<<endl;
						string* reason = res->getData("reason");
						if(reason){
							cout<<"Request failed: "<<*(reason)<<endl;
						}
					}
				}else{
					cout<<"UNFINISHED"<<endl;
					cout<<"Request failed to complete"<<endl;
				}
			}
		}catch(const bad_cast& err){
			cout<<"Couldn't cast SignalEvent to ActionResult..."<<endl;
		}
	},[=](SignalEvent* e){
		//on process
		stringstream ss;
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(!ent){
				res->resolve(false);
				ss<<"Can't attack because Entity is NULL";
			}else if(!ent->isAlive()){
				res->resolve(false);
				ss<<ent->getType()<<"-"<<ent->getID()<<" can't attack because they are dead";
			}else if(!target){
				res->resolve(false);
				ss<<ent->getType()<<"-"<<ent->getID()<<" can't attack because target is NULL";
			}else if(!target->isAlive()){
				res->resolve(false);
				ss<<ent->getType()<<"-"<<ent->getID()<<" can't attack because "<<target->getType()<<"-"<<target->getID()<<" is dead";
			}

			cout<<res->getRequestID()<<" Processing..."<<endl;
			if(res->isFinished() && !res->isSuccess()){
				res->setData("reason", ss.str());
			}
		}catch(const bad_cast& err){
			cout<<"Couldn't cast SignalEvent to ActionResult..."<<endl;
		}
	});

	cout<<ent->getType()<<"-"<<ent->getID()<<" created a request ("<<req->getID()<<")"<<endl;

	return req;
}

void requestTest(){
	ActionManager* actionManager = new ActionManager();

	Citizen* solA = new Soldier(100,"Atlantis",15);
	Citizen* solB = new Soldier(100,"Bethleham",15);

	cout<<solA->printInfo()<<endl;
	cout<<solB->printInfo()<<endl;

	// actionManager->pushRequest( requestAttack(solA, solB) );
	// actionManager->pushRequest( requestAttack(solB, solA) );
	int step = 0;
	int maxStep = 20;

	while(solA->isAlive() && solB->isAlive() && step<maxStep){
		cout<<"-----Step "<<step<<"------------"<<endl;
		///make requests
		actionManager->pushRequest( requestAttack(solA, solB) );
		actionManager->pushRequest( requestAttack(solB, solA) );
		///run requests
		cout<<">> RUNNING REQUESTS..."<<endl;
		while(!actionManager->isEmptyQueue()){
			cout<<"next request..."<<endl;
			actionManager->handleCurrRequest();
		}
		//get queue for next step
		actionManager->placeNextQueue();

		
		///increment step count
		// war->incrementStep();
		step++;

		///view initial results
		cout<<solA->printInfo()<<endl;
		cout<<solB->printInfo()<<endl;
	}

	
	
	
	

}

int main(){
	requestTest();
	// managerTest();
	// cout<<"Coin "<<myHelper::coinFlip()<<endl;

	return 0;
}