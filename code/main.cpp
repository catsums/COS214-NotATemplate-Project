#include <iostream>
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"
#include "Entity.cpp"
#include "SoldierFactory.cpp"
<<<<<<< Updated upstream
#include "MedicFactory.cpp"
#include "InformantFactory.cpp"
#include "PoliticianFactory.cpp"
=======

>>>>>>> Stashed changes


using namespace std; 


int main()
{

	//Soldier testing 
	// Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed");

	//Medic testing
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed");

<<<<<<< Updated upstream
	// Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed", "Land");
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed", "Sea");
=======
	//Informant testing
>>>>>>> Stashed changes
	// Citizen *myInformant= new Informant(20,"United Kingdom", "Undercover");

	//Politician testing
	// Citizen *myPolitician= new Politician(10,"Romania", "Moderate");

	// delete mySoldier;
	// delete myMedic;
	// delete myInformant;
	// delete myPolitician;

<<<<<<< Updated upstream

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
=======

	//SoldierFactory testing 
	Entity* test1 = new SoldierFactory();

	Citizen* mySoldier1 = test1->createEntity(50,"SA");

>>>>>>> Stashed changes

	delete myPoli;
	delete test4;

<<<<<<< Updated upstream
=======
	delete mySoldier1;
	delete test1;
>>>>>>> Stashed changes



}