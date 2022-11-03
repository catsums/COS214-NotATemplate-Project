#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"

#include "Vehicle.cpp"
#include "Artillery.cpp"
#include "Tank.cpp"
#include "FighterJet.cpp"
#include "Submarine.cpp"
#include "Transport.cpp"



using namespace std; 


int main()
{

	Artillery *test = new Tank();

	test->infoSummary();

	cout<<endl;
	test->decreaseFeul(test,5);



	test->infoSummary();
	cout<<endl;
	


	// Citizen *test2 = new Medic();

	// test2->infoSummary();


	// test->recieveHp(test2->getHeal());


	// cout<<endl;


	// test->infoSummary();


	delete test;
	// delete test2;

}