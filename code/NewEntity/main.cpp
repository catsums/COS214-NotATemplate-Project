#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

#include "Entity.h"
#include "Medic.h"
#include "Soldier.h"

#include "TransportVehicle.h"
#include "BattleVehicle.h"

using namespace std;

int main(){

	Citizen* entA = new Citizen(20, "USA");
	Citizen* entB = new Soldier(10, "USA");

	Medic* medicA = new Medic(*entA);

	TransportVehicle* truck = new TransportVehicle(30,"USA",100);
	truck->carryEntity(medicA);
	truck->carryEntity(entB);

	Entity* dropee = truck->dropOff(entA);

	Citizen* ddd = static_cast<Citizen*>(entA);

	BattleVehicle* tank = new BattleVehicle(100,"Zimbabwe",100,5);

	cout<<"Soldier hp: "<<entB->getHP()<<endl;

	tank->attack(entB);

	medicA->healPerson(entB);

	cout<<"Soldier hp: "<<entB->getHP()<<endl;


	return 0;
}