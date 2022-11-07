#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"
#include "../myHelper.cpp"

using namespace std;

Battle::Battle(Country* aa,Country* bb){
	a = aa; b = bb;
}
Battle::~Battle(){
	a = NULL; b = NULL;
}

Entity* Battle::getRandomItemFrom(vector<Entity*> arr){
	int index = myHelper::getRandomInt(0, arr.size());

	return arr[index];
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

ActionRequest* requestAttack(Entity* currEnt, Entity* targetEnt){

	ActionRequest* req = new ActionRequest(getRandomInt(0,4),[=](SignalEvent* e){
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
						cout<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" attacked "<<targetEnt->getType()<<"-"<<targetEnt->getCountry()<<endl;
						shiftBalance(currEnt->getCountry());
						if(newHP<=0){
							cout<<currEnt->getType()<<" defeated the entity!"<<endl;
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
			if(!currEnt){
				res->resolve(false);
				ss<<"Can't attack because Entity is NULL";
			}else if(!currEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't attack because they are down";
			}else if(!targetEnt){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't attack because target is NULL";
			}else if(!targetEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't attack because "<<targetEnt->getType()<<"-"<<targetEnt->getCountry()<<" is dead";
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
ActionRequest* requestHeal(Entity* currEnt, Entity* targetEnt){

	ActionRequest* req = new ActionRequest(getRandomInt(0,4),[=](SignalEvent* e){
		//onFulfill
		try{
			ActionResult* res = static_cast<ActionResult*>(e);
			if(res->isFinished()){
				if(res->isSuccess()){
					// cout<<res->getRequestID()<<" - SUCCESS"<<endl;
					try{
						Medic* medicA = static_cast<Medic*>(currEnt);
					


					}catch(const bad_cast& err){
						cout<<"Can't cast Entity to Medic"<<endl;
						return;
					}
					int healAmt = medicA->getHeal();
					int hp = targetEnt->getHp();
					targetEnt->recieveHp(healAmt);
					int newHP = targetEnt->getHp();
					if(newHP<hp){
						cout<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" healed "<<targetEnt->getType()<<"-"<<targetEnt->getCountry()<<endl;
						shiftBalance(currEnt->getCountry());
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
			if(!currEnt){
				res->resolve(false);
				ss<<"Can't heal because Entity is NULL";
			}else if(!currEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't heal because they are down";
			}else if(!targetEnt){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't heal because target is NULL";
			}else if(!targetEnt->isAlive()){
				res->resolve(false);
				ss<<currEnt->getType()<<"-"<<currEnt->getCountry()<<" can't heal because "<<targetEnt->getType()<<"-"<<targetEnt->getCountry()<<" is dead";
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

bool Battle::commenceBattle(){
	preparationPhase();
	int newBalance;
	if(!actionManager->isEmptyQueue()){
		newBalance = executionPhase();
	}

	evaluationPhase();
}

void Battle::preparationPhase(){
	
	// ArmyForce* forceA = a->getArmyForce();
	// ArmyForce* forceB = b->getArmyForce();

	// vector<Entity*> entsA = forceA->getEntities();
	// vector<Entity*> entsB = forceB->getEntities();

	vector<Entity*> entsA = a->getEntities();
	vector<Entity*> entsB = b->getEntities();

	//teamA preparations
	for(int i=0;i<(int)entsA.size();i++){
		Entity* ent = entsA[i];
		if(ent->isType("Citizen")){
			if(ent->isType("Soldier")){
				Entity* target = getRandomItemFrom(entsB);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to attack "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}else if(ent->isType("Medic")){
				Entity* target = getRandomItemFrom(entsA);
				ActionRequest* req = requestHeal(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to heal "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}
		}else if(ent->isType("Vehicle")){
			if(ent->isType("Artillery")){
				Entity* target = getRandomItemFrom(entsB);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to attack "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}
		}
	}

	//teamB preparations
	for(int i=0;i<(int)entsA.size();i++){
		Entity* ent = entsB[i];
		if(ent->isType("Citizen")){
			if(entA->isType("Soldier")){
				Entity* target = getRandomItemFrom(entsA);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to attack "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}else if(ent->isType("Medic")){
				Entity* target = getRandomItemFrom(entsB);
				ActionRequest* req = requestHeal(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to heal "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}
		}else if(ent->isType("Vehicle")){
			if(ent->isType("Artillery")){
				Entity* target = getRandomItemFrom(entsA);
				ActionRequest* req = requestAttack(ent,target);
				actionManager->pushRequest(req);
				cout<<ent->getType()<<"-"<<ent->getCountry()<<" requested to attack "<<target->getType()<<"-"<<target->getCountry()<<endl;
			}
		}
	}

}

int Battle::executionPhase(){
	int step = 0;
	int maxStep = 20;
	while(!actionManager->isEmptyQueue() && step<maxStep){
		while(!actionManager->isEmptyQueue()){
			actionManager->handleCurrRequest();
		}
		//get queue for next requests
		actionManager->placeNextQueue();
		//increment step
		step++;
	}

	return balance;
}

void Battle::evaluationPhase(){
	if(balance<0){
		winner = a;
	}else if(balance>0){
		winner = b;
	}else{
		winner = NULL; //draw
	}
}

#endif