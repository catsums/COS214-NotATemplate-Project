#include <iostream>
#include "Vehicle.cpp"
#include "ArmyVehicle.cpp"
#include "TransportVehicle.cpp"
#include "LandVehicle.cpp"
#include "Tank.cpp"
#include "CargoTruck.cpp"
#include "AirVehicle.cpp"
#include "Fighterjet.cpp"
#include "CargoPlane.cpp"
#include "SeaVehicle.cpp"
#include "Submarine.cpp"
#include "CargoShip.cpp"




using namespace std; 


int main()
{

	//This main tests the resources structure aka the Abstract Factory Pattern

	//LAND

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

	cout<< endl;

	///////////////////////////////////////////////////////
	//AIR
	//Testing the creation of an air vehicle aka Fighterjet
	Vehicle *army3 = new ArmyVehicle();

	AirVehicle* myFighterjet = army3->createAirVehicle();

	delete myFighterjet;
	delete army3;

	cout<< endl;

	//Testing the creation of a air vehicle aka CargoPLane
	Vehicle *army4 = new TransportVehicle();

	AirVehicle* myCargoPlane= army4->createAirVehicle();

	delete myCargoPlane;
	delete army4;

	cout<< endl;

	///////////////////////////////////////////////////////
	//SEA
	//Testing the creation of an Sea vehicle aka Submarine
	Vehicle *army5 = new ArmyVehicle();

	SeaVehicle* mySubmarine = army5->createSeaVehicle();

	delete mySubmarine;
	delete army5;

	cout<< endl;

	//Testing the creation of a Sea vehicle aka CargoShip
	Vehicle *army6 = new TransportVehicle();

	SeaVehicle* myCargoShip= army6->createSeaVehicle();

	delete myCargoShip;
	delete army6;

	cout<< endl;
}