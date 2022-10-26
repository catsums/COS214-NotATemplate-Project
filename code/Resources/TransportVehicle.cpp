#include <string>
#include <iostream>
#include "Vehicle.h"
#include "TransportVehicle.h"
#include "LandVehicle.h"
#include "CargoTruck.h"
#include "AirVehicle.h"
#include "CargoPlane.h"
#include "SeaVehicle.h"
#include "CargoShip.h"


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

	AirVehicle* TransportVehicle::createAirVehicle()
	{
		AirVehicle *myCargoPlane = new CargoPlane();

		return myCargoPlane;
	}

	SeaVehicle* TransportVehicle::createSeaVehicle()
	{
		SeaVehicle *myCargoShip = new CargoShip();

		return myCargoShip;
	}
	
