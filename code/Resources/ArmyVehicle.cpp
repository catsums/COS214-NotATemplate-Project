#include <string>
#include <iostream>
#include "Vehicle.h"
#include "ArmyVehicle.h"
#include "LandVehicle.h"
#include "Tank.h"


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

	

