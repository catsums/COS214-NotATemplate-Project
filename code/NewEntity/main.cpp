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

using namespace std;

int main(){

	Citizen* entA = new Citizen(10, "USA");
	Citizen* entB = new Soldier(10, "USA");

	Citizen* medicA = new Medic(*entA);

	TransportVehicle* truck = new TransportVehicle(30,"USA",100);
	truck->carryEntity(medicA);
	truck->carryEntity(entB);

	Entity* dropee = truck->dropOff(entA);

	Citizen* ddd = static_cast<Citizen*>(entA);

	if(ddd == entA){
		cout<<"SUCCESS"<<endl;
	}else{
		cout<<"HUH."<<endl;
	}

	return 0;
}