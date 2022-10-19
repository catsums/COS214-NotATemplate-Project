#include <iostream>
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"
#include "Entity.cpp"
#include "SoldierFactory.cpp"
#include "MedicFactory.cpp"
#include "InformantFactory.cpp"
#include "PoliticianFactory.cpp"


using namespace std; 


int main()
{

	// Citizen myCitizen;

	// myCitizen.setType("Soldier");
	// myCitizen.printInfo();

	// Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed", "Land");
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed", "Sea");
	// Citizen *myInformant= new Informant(20,"United Kingdom", "Undercover");
	// Citizen *myPolitician= new Politician(10,"Romania", "Moderate");

	// delete mySoldier;
	// delete myMedic;
	// delete myInformant;
	// delete myPolitician;


	Entity* test1 = new SoldierFactory();

	Citizen* mySoldier = test1->createEntity(50,"SA");

	cout<<endl;


	Entity* test2 = new MedicFactory();

	Citizen* myMedic = test2->createEntity(20,"UK");

	cout<<endl;


	Entity* test3 = new InformantFactory();

	Citizen* myInfor = test3->createEntity(30,"USA");

	cout<<endl;


	Entity* test4 = new PoliticianFactory();

	Citizen* myPoli = test4->createEntity(10,"UAE");

	cout<<endl;




	delete mySoldier;
	delete test1;

	delete myMedic;
	delete test2;


	delete myInfor;
	delete test3;

	delete myPoli;
	delete test4;




}