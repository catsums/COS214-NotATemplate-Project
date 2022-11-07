#include <string>
#include <iostream>
#include "EntityFactory.h"


using namespace std;

	EntityFactory::EntityFactory()// default constuctor 
	{
		//cout<<"EntityFactory’s Constructor was Called"<<endl;


	} 

	
	EntityFactory::~EntityFactory() //destructor
	{
		//cout<<"EntityFactory’s Destructor was Called"<<endl;
	}

	
	
	Citizen* EntityFactory::createCitizen()
	{
		return new Citizen;
	}

	/*
	This function instantiates new vehicle entities 
	and returns a refernce to it
	*/
	Vehicle* EntityFactory::createLandVehicle()
	{
		return new Vehicle;
	}
	
	Vehicle* EntityFactory::createAirVehicle()
	{
		return new Vehicle;
	}

	Vehicle* EntityFactory::createSeaVehicle()
	{
		return new Vehicle;
	}

