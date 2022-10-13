#include <iostream>
#include "Citizen.cpp"


using namespace std; 


int main()
{

	Citizen *myCitizen= new Citizen(45,"South Africa");
	delete myCitizen;
}