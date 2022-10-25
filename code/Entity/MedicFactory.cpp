#include <string>
#include <iostream>
#include "Entity.h"
#include "MedicFactory.h"
#include "Citizen.h"
#include "Medic.h"


using namespace std;

	MedicFactory::MedicFactory()// default constuctor 
	{

	} 

	
	MedicFactory::~MedicFactory() //destructor
	{
		cout<<"MedicFactory’s Destructor was Called"<<endl;
	}

	
	Citizen* MedicFactory::createEntity(int health,string country)
	{	
		Medic *myS= new Medic();
		Citizen *myCitizen= myS;
		myCitizen->setHP(health);
		myCitizen->setCountry(country);
		myCitizen->printInfo();
		//myS->printMedicInfo();



		return myCitizen;
	}

	

	

