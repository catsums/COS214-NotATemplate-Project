#include <iostream>
#include "Citizen.cpp"
#include "Soldier.cpp"


using namespace std; 


int main()
{

	Citizen *myCitizen= new Soldier(50,"South Africa", "Stationed", "Land");
	delete myCitizen;
}