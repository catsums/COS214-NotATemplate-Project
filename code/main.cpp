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

// #include "NewEntity/SoldierFactory.h"
// #include "NewEntity/MedicFactory.h"
// #include "NewEntity/Tank.h"
// #include "NewEntity/Truck.h"
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
	}

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