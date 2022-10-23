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

	//Soldier testing 
	// Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed");

	//Medic testing
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed");


	// Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed", "Land");
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed", "Sea");

	//Informant testing

	// Citizen *myInformant= new Informant(20,"United Kingdom", "Undercover");

	//Politician testing
	// Citizen *myPolitician= new Politician(10,"Romania", "Moderate");

	// delete mySoldier;
	// delete myMedic;
	// delete myInformant;
	// delete myPolitician;





	//SoldierFactory testing 
	Entity* test1 = new SoldierFactory();

	Citizen* mySoldier1 = test1->createEntity(50,"SA");


	delete mySoldier1;
	delete test1;

	//MedicFactory testing 
	Entity* test2 = new MedicFactory();

	Citizen* myMedic1 = test2->createEntity(10,"USA");


	delete myMedic1;
	delete test2;

	//InformantFactory testing 
	Entity* test3 = new InformantFactory();

	Citizen* myInformant1 = test3->createEntity(20,"UAE");


	delete myInformant1;
	delete test3;


	//PoliticianFactory testing 
	Entity* test4 = new PoliticianFactory();

	Citizen* myPolitician1 = test4->createEntity(8,"UK");


	delete myPolitician1;
	delete test4;

}