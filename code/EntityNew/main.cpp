#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Vehicle.cpp"
#include "Soldier.cpp"




using namespace std; 


int main()
{

	Citizen *test = new Soldier();

	test->infoSummary();

	delete test;


	// Entity *test2 = new Vehicle(12,"Uk",12,4,5);

	// test2->infoSummary();

	// delete test2;

}