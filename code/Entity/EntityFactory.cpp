#include <string>
#include <iostream>
#include "EntityFactory.h"
#include "Citizen.h"
#include "Vehicle.h"



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
	Vehicle* EntityFactory::createVehicle(string)
	{
		return new Vehicle;
	}
	

