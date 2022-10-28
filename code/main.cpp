#include <iostream>
#include "Citizen.cpp"
#include "Soldier.cpp"
#include "Medic.cpp"
#include "Informant.cpp"
#include "Politician.cpp"
#include "Entity.cpp"
//#include "SoldierFactory.cpp"
#include "Map/Map.cpp"
#include "Map/Zone.cpp"

using namespace std; 

void Testing();
void MarkTestCode();
void OtherTestCode();

int main()
{
	Testing();
}

void Testing()
{
	MarkTestCode();
	//OtherTestCode();
}

void MarkTestCode()
{
	Map* m = new Map();
	cout << m->getZoneCount() << endl;
}

void OtherTestCode()
{
	// Citizen myCitizen;

	// myCitizen.setType("Soldier");
	// myCitizen.printInfo();

	//Citizen *mySoldier= new Soldier(50,"South Africa", "Stationed", "Land");
	// Citizen *myMedic= new Medic(20,"Russia", "Stationed", "Sea");
	// Citizen *myInformant= new Informant(20,"United Kingdom", "Undercover");
	// Citizen *myPolitician= new Politician(10,"Romania", "Moderate");

	//delete mySoldier;
	// delete myMedic;
	// delete myInformant;


	//Entity* test1 = new SoldierFactory();

	//Citizen* mySoldier = test1->createEntity(50,"Sa");


	//delete mySoldier;
	//delete test1;
}