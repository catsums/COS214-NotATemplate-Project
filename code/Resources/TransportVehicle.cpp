#include <string>
#include <iostream>
#include "Vehicle.h"
#include "TransportVehicle.h"
#include "LandVehicle.h"
#include "CargoTruck.h"


using namespace std;

	TransportVehicle::TransportVehicle()// default constuctor 
	{
		
	} 

	
	TransportVehicle::~TransportVehicle() //destructor
	{
		cout<<"TransportVehicle’s Destructor was Called"<<endl;
	}

	
	LandVehicle* TransportVehicle::createLandVehicle()
	{
		LandVehicle *myCargoTruck = new CargoTruck();

		return myCargoTruck;
	}

	

