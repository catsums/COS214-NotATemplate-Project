#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"

#include "Vehicle.cpp"
#include "Artillery.cpp"




using namespace std; 


int main()
{

	Vehicle *test = new Artillery();

	test->infoSummary();

	


	// Citizen *test2 = new Medic();

	// test2->infoSummary();


	// test->recieveHp(test2->getHeal());


	// cout<<endl;


	// test->infoSummary();


	delete test;
	// delete test2;

}