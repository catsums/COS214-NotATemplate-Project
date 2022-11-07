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
		return NULL;
	}
	
	Vehicle* EntityFactory::createAirVehicle()
	{
		return NULL;
	}

	Vehicle* EntityFactory::createSeaVehicle()
	{
		return NULL;
	}

