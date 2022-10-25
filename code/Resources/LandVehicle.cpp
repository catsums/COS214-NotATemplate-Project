#include <string>
#include <iostream>
#include "LandVehicle.h"


using namespace std;

	LandVehicle::LandVehicle()// default constuctor 
	{
		fuel = 20;
	} 

	
	LandVehicle::~LandVehicle() //destructor
	{
		cout<<"LandVehicle’s Destructor was Called"<<endl;
	}

	
	

	int LandVehicle::getFuel()
	{
		return fuel;
	}


	//setters
	void LandVehicle::setFuel(int f)
	{
		fuel = f;
	}

	

