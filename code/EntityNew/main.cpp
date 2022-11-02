#include <iostream>

#include "Entity.cpp"
#include "Citizen.cpp"




using namespace std; 


int main()
{

	Entity *test = new Citizen();

	delete test;

}