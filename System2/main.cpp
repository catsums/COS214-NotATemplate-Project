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

#include "Army/GroundForce.h"
#include "Army/NavalForce.h"
#include "Army/AirForce.h"
#include "Entity/Soldier.h"

// #include "War/War.h"
// #include "War/WarPhases.h"

#include "Battle/Battle.h"

#include "myHelper.cpp"

using namespace std;

int getRandomInt(int a, int b){
	return myHelper::uniformDistribution<int>(a,b);
}

string getRandomString(int size){
	return myHelper::randomString(size);
}


void battleTest(){
	Country* c1 = new Country("Athens");
	Country* c2 = new Country("Bobas");

	for(int i=0;i<2;i++){
		c1->getArmy()->recruitSoldier();
		c2->getArmy()->recruitSoldier();
		c1->getArmy()->createLandVehicle();
		c2->getArmy()->createSeaVehicle();
		c1->getArmy()->createAirVehicle();
	}

	c1->getArmy()->setForce(new GroundForce());
	c2->getArmy()->setForce(new NavalForce());

	cout<<c1->getName()<<" - "<<c1->getArmy()->getForce()->getStrategyName()<<endl;
	cout<<c1->getArmy()->getActiveForce().size()<<endl;

	cout<<c2->getName()<<" - "<<c2->getArmy()->getForce()->getStrategyName()<<endl;
	cout<<c2->getArmy()->getActiveForce().size()<<endl;

	Battle* battle = new Battle(c1,c2);

	battle->commenceBattle();

	if(battle->getWinner()){
		Country* winner = battle->getWinner();
		cout<<"The winner is "<<winner->getName()<<endl;
	}else{
		cout<<"The battle is a draw"<<endl;
	}

}

int main(){
	battleTest();
	// managerTest();
	// cout<<"Coin "<<myHelper::coinFlip()<<endl;

	return 0;
}