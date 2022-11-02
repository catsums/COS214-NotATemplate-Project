#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"
#include "Vehicle.cpp"




using namespace std; 


int main()
{

	Entity *test = new Citizen();

	test->infoSummary();

	delete test;

}