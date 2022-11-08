#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"
#include "../myHelper.cpp"

using namespace std;

Battle::Battle(Country* aa,Country* bb, int t){
	a = aa; b = bb;

	theatre = t;

	winner = NULL;
	signalBus = new SignalBus();
	actionManager = new ActionManager();
}
Battle::~Battle(){
	a = NULL; b = NULL;
	winner = NULL;
}

void Battle::shiftBalance(string side){
	if(side == a->getName()){
		balance--;	//shift towards A
	}else if(side == b->getName()){
		balance++;	//shift towards B
	}
}
void Battle::lowerBalance(string side){
	if(side == a->getName()){
		balance++;	//shift away from A
	}else if(side == b->getName()){
		balance--;	//shift away from B
	}
}

ActionRequest* Battle::requestTakeover(Entity* currEnt){
	ActionRequest* req = new ActionRequest(myHelper::randomInt(0,4),[=](SignalEvent* e){
		//onFulfill
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(res->isFinished()){
				if(res->isSuccess()){
					// cout<<res->getRequestID()<<" - SUCCESS"<<endl;
					cout<<currEnt->getTitle()<<" is taking over the zone with the army."<<endl;
					shiftBalance(currEnt->getCountry());
				}else{
					// cout<<res->getRequestID()<<" - FAIL"<<endl;
					string* reason = res->getData("reason");
					if(reason){
						cout<<"Request failed: "<<*(reason)<<endl;
					}
				}
			}else{
				cout<<"Request failed to complete"<<endl;
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	},[=](SignalEvent* e){
		//onProcess
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			stringstream ss;
			if(!currEnt){
				res->resolve(false);
				ss<<"Can't takeover because Entity is NULL";
			}else if(!currEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't takeover because they are down";
			}

			// cout<<res->getRequestID()<<" Processing..."<<endl;
			if(res->isFinished() && !res->isSuccess()){
				res->setData("reason", ss.str());
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	});

	return req;
}

ActionRequest* Battle::requestAttack(Entity* currEnt, Entity* targetEnt){

	ActionRequest* req = new ActionRequest(myHelper::randomInt(0,4),[=](SignalEvent* e){
		//onFulfill
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(res->isFinished()){
				if(res->isSuccess()){
					// cout<<res->getRequestID()<<" - SUCCESS"<<endl;
					int dmg = currEnt->dealDamage();
					int hp = targetEnt->getHp();
					targetEnt->takeDamage(dmg);
					int newHP = targetEnt->getHp();
					if(newHP<hp){
						cout<<currEnt->getTitle()<<" attacked "<<targetEnt->getTitle()<<endl;
						shiftBalance(currEnt->getCountry());
						if(newHP<=0){
							cout<<currEnt->getTitle()<<" defeated the entity!"<<endl;
							shiftBalance(currEnt->getCountry());
						}
					}
					
				}else{
					// cout<<res->getRequestID()<<" - FAIL"<<endl;
					string* reason = res->getData("reason");
					if(reason){
						cout<<"Request failed: "<<*(reason)<<endl;
					}
				}
			}else{
				cout<<"Request failed to complete"<<endl;
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	},[=](SignalEvent* e){
		//onProcess
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			stringstream ss;
			if(!currEnt){
				res->resolve(false);
				ss<<"Can't attack because Entity is NULL";
			}else if(!currEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't attack because they are down";
			}else if(!targetEnt){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't attack because target is NULL";
			}else if(!targetEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't attack because "<<targetEnt->getTitle()<<" is dead";
			}

			// cout<<res->getRequestID()<<" Processing..."<<endl;
			if(res->isFinished() && !res->isSuccess()){
				res->setData("reason", ss.str());
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	});

	return req;
}
ActionRequest* Battle::requestHeal(Entity* currEnt, Entity* targetEnt){

	ActionRequest* req = new ActionRequest(myHelper::randomInt(0,4),[=](SignalEvent* e){
		//onFulfill
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(res->isFinished()){
				if(res->isSuccess()){
					// cout<<res->getRequestID()<<" - SUCCESS"<<endl;
					try{
						Medic* medicA = static_cast<Medic*>(currEnt);
						int healAmt = medicA->getHeal();
						int hp = targetEnt->getHp();
						targetEnt->recieveHp(healAmt);
						int newHP = targetEnt->getHp();
						if(newHP<hp){
							cout<<medicA->getTitle()<<" healed "<<targetEnt->getTitle()<<endl;
							shiftBalance(medicA->getCountry());
						}

					}catch(const bad_cast& err){
						cout<<"Can't cast Entity to Medic"<<endl;
						return;
					}
					
					
				}else{
					// cout<<res->getRequestID()<<" - FAIL"<<endl;
					string* reason = res->getData("reason");
					if(reason){
						cout<<"Request failed: "<<*(reason)<<endl;
					}
				}
			}else{
				cout<<"Request failed to complete"<<endl;
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	},[=](SignalEvent* e){
		//onProcess
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			stringstream ss;
			if(!currEnt){
				res->resolve(false);
				ss<<"Can't heal because Entity is NULL";
			}else if(!currEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't heal because they are down";
			}else if(!targetEnt){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't heal because target is NULL";
			}else if(!targetEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getTitle()<<" can't heal because "<<targetEnt->getTitle()<<" is dead";
			}

			// cout<<res->getRequestID()<<" Processing..."<<endl;
			if(res->isFinished() && !res->isSuccess()){
				res->setData("reason", ss.str());
			}
		}catch(const bad_cast& err){
			cout<<"Can't cast SignalEvent to ActionResult"<<endl;
		}
	});

	return req;
}

void Battle::commenceBattle(){
	cout<<"BATTLE-Preparation Phase..."<<endl;
	preparationPhase();
	// cout<<"ended prep"<<endl;
	if(!actionManager->isEmptyQueue()){
		cout<<"BATTLE-Execution Phase..."<<endl;
		executionPhase();
	}
	cout<<"BATTLE-Evaluation Phase..."<<endl;
	evaluationPhase();
}

void Battle::preparationPhase(){
	
	Army* armyA = a->getArmy();
	Army* armyB = b->getArmy();



	vector<Entity*> entsA = armyA->getActiveForce();
	vector<Entity*> entsB = armyB->getActiveForce();

	//teamA preparations
	for(int i=0;i<(int)entsA.size();i++){
		Entity* ent = entsA[i];
		if(entsB.empty()){
			ActionRequest* req = requestTakeover(ent);
			actionManager->pushRequest(req);
			cout<<ent->getTitle()<<" requested to takeover the zone directly "<<endl;
			continue;
		}
		// cout<<"1"<<endl;
		if(ent->isType("Citizen")){
			// cout<<"aa"<<endl;
			if(ent->isType("Soldier")){
				// cout<<"bb"<<endl;
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsB);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to attack "<<target->getTitle()<<endl;
			
			}else if(ent->isType("Medic")){
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsA);
				ActionRequest* req = requestHeal(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to heal "<<target->getTitle()<<endl;
			}
			// else if(ent->isType("Informant")){
			// 	Entity* target = myHelper::getRandomItemFrom<Entity*>(entsB);
			// 	ActionRequest* req = requestObserve(ent,target);
			// 	actionManager->pushRequest(req);
			// 	cout<<ent->getTitle()<<" requested to observe "<<target->getTitle()<<endl;
			// }
		}else if(ent->isType("Vehicle")){
			if(ent->isType("Artillery")){
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsB);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to attack "<<target->getTitle()<<endl;
			}
		}
		// cout<<"2"<<endl;
	}
	// cout<<"c"<<endl;
	//teamB preparations
	for(int i=0;i<(int)entsB.size();i++){
		Entity* ent = entsB[i];
		// cout<<"1"<<endl;
		if(!ent) continue;
		if(entsA.empty()){
			ActionRequest* req = requestTakeover(ent);
			actionManager->pushRequest(req);
			cout<<ent->getTitle()<<" requested to takeover the zone directly "<<endl;
			continue;
		}
		// cout<<"2"<<endl;
		if(ent->isType("Citizen")){
			// cout<<"3"<<endl;
			if(ent->isType("Soldier")){
				// cout<<"4"<<endl;
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsA);
				// cout<<"5"<<endl;
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to attack "<<target->getTitle()<<endl;
				// cout<<"6"<<endl;
			}else if(ent->isType("Medic")){
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsB);
				ActionRequest* req = requestHeal(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to heal "<<target->getTitle()<<endl;
			}
			// else if(ent->isType("Informant")){
			// 	Entity* target = myHelper::getRandomItemFrom<Entity*>(entsA);
			// 	ActionRequest* req = requestObserve(ent,target);
			// 	actionManager->pushRequest(req);
			// 	cout<<ent->getTitle()<<" requested to observe "<<target->getTitle()<<endl;
			// }
		}else if(ent->isType("Vehicle")){
			if(ent->isType("Artillery")){
				Entity* target = myHelper::getRandomItemFrom<Entity*>(entsA);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getTitle()<<" requested to attack "<<target->getTitle()<<endl;
			}
		}
	}
	// cout<<"d"<<endl;
}

int Battle::executionPhase(){
	int step = 0;
	int maxStep = 20;
	while(!actionManager->isEmptyQueue() && step<maxStep){
		cout<<"Step "<<step<<"-----"<<endl;
		while(!actionManager->isEmptyQueue()){
			actionManager->handleCurrRequest();
		}
		//get queue for next requests
		actionManager->placeNextQueue();
		//increment step
		step++;
		if(step==0){
			cin.get();
		}
	}

	return balance;
}

void Battle::evaluationPhase(){
	finished = true;
	if(balance<0){
		winner = a;
	}else if(balance>0){
		winner = b;
	}else{
		winner = NULL; //draw
	}

	int victoryChance = ((double) a->getTerritory() / (a->getTerritory() + b->getTerritory())) * 100;
    
    if((rand() % 100 + 1) <= victoryChance)
    {
        int t = (rand() % 20 + 1);
        cout << a->getName() << " has defeated " << b->getName() << " in battle | " << a->getName() << " has captured " << t << " territory" << endl;
        
        a->updateTerritory(t, t);
        b->updateTerritory(-t, -t);

        a->getArmy()->sufferCasualties(0.6);
        b->getArmy()->sufferCasualties(0.8);
    }
    else
    {
        cout << b->getName() << " has defeated " << a->getName() << " in battle | " << b->getName() << " has defended their territory" << endl;
        a->getArmy()->sufferCasualties(0.8);
        b->getArmy()->sufferCasualties(0.4);
    }
}

vector<Entity*> Battle::getAllBattleEntities(){
	Army* armyA = a->getArmy();
	Army* armyB = b->getArmy();

	vector<Entity*> entsA = armyA->getEntities();
	vector<Entity*> entsB = armyB->getEntities();

	vector<Entity*> allEnts;

	allEnts.insert( allEnts.end(), entsA.begin(), entsA.end() );
	allEnts.insert( allEnts.end(), entsB.begin(), entsB.end() );

	return allEnts;

}

// void Battle::onIntel(string action, string id){
// 	Entity* target;

// 	vector<Entity*> ents = getAllBattleEntities();

// 	for(int i=0;i<(int)ents.size();i++){
// 		Entity* ent = ents[i];
// 		if(ent && ent->getID() == id){
// 			target = ent;
// 			break;
// 		}
// 	}

// 	if(target){
// 		Country* currC;
// 		if(target->getCountry() == a->getName()){
// 			currC = a;
// 		}else if(target->getCountry() == b->getName()){
// 			currC = b;
// 		}
// 		if(!currC) return;

// 		vector<Entity*> activeForce = currC->getActiveForce();
// 		if(activeForce.empty()) return;

// 		if(action == "attack" || action == "heal"){
// 			//take revenge
// 			Entity* currEnt = myHelper::getRandomItemFrom<Entity*>(activeForce);
// 			ActionRequest* req = requestAttack(currEnt,target);
// 			actionManager->pushRequest(req);
// 			cout<<currEnt->getTitle()<<" requested to attack "<<target->getTitle()<<endl;
// 		}

// 	}
// }

#endif