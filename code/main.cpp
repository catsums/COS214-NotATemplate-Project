#include <iostream>
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"
#include "Entity.cpp"
#include "SoldierFactory.cpp"


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

}