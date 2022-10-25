#include <iostream>
#include "Vehicle.cpp"
#include "ArmyVehicle.cpp"
#include "TransportVehicle.cpp"
#include "LandVehicle.cpp"
#include "Tank.cpp"
#include "CargoTruck.cpp"



using namespace std; 


int main()
{

	//This main tests the resources structure aka the Abstract Factory Pattern


	//Testing the creation of an army land vehicle aka tank
	Vehicle *army1 = new ArmyVehicle();

	LandVehicle* myTank = army1->createLandVehicle();

	delete myTank;
	delete army1;

	cout<< endl;

	//Testing the creation of a transport land vehicle aka tank
	Vehicle *army2 = new TransportVehicle();

	LandVehicle* myCargoTruck = army2->createLandVehicle();

	delete myCargoTruck;
	delete army2;




}