#include <string>
#include <iostream>
#include "AirVehicle.h"


using namespace std;

	AirVehicle::AirVehicle()// default constuctor 
	{
		fuel = 20;
	} 

	
	AirVehicle::~AirVehicle() //destructor
	{
		cout<<"AirVehicle’s Destructor was Called"<<endl;
	}

	
	

	int AirVehicle::getFuel()
	{
		return fuel;
	}


	//setters
	void AirVehicle::setFuel(int f)
	{
		fuel = f;
	}

	
