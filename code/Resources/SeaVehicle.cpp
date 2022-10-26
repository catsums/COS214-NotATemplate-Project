#include <string>
#include <iostream>
#include "SeaVehicle.h"


using namespace std;

	SeaVehicle::SeaVehicle()// default constuctor 
	{
		fuel = 20;
	} 

	
	SeaVehicle::~SeaVehicle() //destructor
	{
		cout<<"SeaVehicle’s Destructor was Called"<<endl;
	}

	
	

	int SeaVehicle::getFuel()
	{
		return fuel;
	}


	//setters
	void SeaVehicle::setFuel(int f)
	{
		fuel = f;
	}

	
