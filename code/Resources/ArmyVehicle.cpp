#include <string>
#include <iostream>
#include "Vehicle.h"
#include "ArmyVehicle.h"
#include "LandVehicle.h"
#include "Tank.h"
#include "AirVehicle.h"
#include "Fighterjet.h"
#include "SeaVehicle.h"
#include "Submarine.h"


using namespace std;

	ArmyVehicle::ArmyVehicle()// default constuctor 
	{
		
	} 

	
	ArmyVehicle::~ArmyVehicle() //destructor
	{
		cout<<"ArmyVehicle’s Destructor was Called"<<endl;
	}

	
	LandVehicle* ArmyVehicle::createLandVehicle()
	{
		LandVehicle *myTank = new Tank();

		return myTank;
	}

	AirVehicle* ArmyVehicle::createAirVehicle()
	{
		AirVehicle *myFighterjet = new Fighterjet();

		return myFighterjet;
	}

	SeaVehicle* ArmyVehicle::createSeaVehicle()
	{
		SeaVehicle *mySubmarine = new Submarine();

		return mySubmarine;
	}

	
