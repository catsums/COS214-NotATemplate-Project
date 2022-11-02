#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Vehicle.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"




using namespace std; 


int main()
{

	Citizen *test = new Soldier();

	test->infoSummary();

	


	Citizen *test2 = new Medic();

	test2->infoSummary();


	test->recieveHp(test2->getHeal());


	cout<<endl;


	test->infoSummary();


	delete test;
	delete test2;

}