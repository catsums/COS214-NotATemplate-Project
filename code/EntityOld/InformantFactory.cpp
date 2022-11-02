#include <string>
#include <iostream>
#include "Entity.h"
#include "InformantFactory.h"
#include "Citizen.h"
#include "Informant.h"


using namespace std;

	InformantFactory::InformantFactory()// default constuctor 
	{

	} 

	
	InformantFactory::~InformantFactory() //destructor
	{
		cout<<"InformantFactory’s Destructor was Called"<<endl;
	}

	
	Citizen* InformantFactory::createEntity(int health,string country)
	{	
		Informant *myS= new Informant();
		Citizen *myCitizen= myS;
		myCitizen->setHP(health);
		myCitizen->setCountry(country);
		myCitizen->printInfo();
		//myS->printInformantInfo();



		return myCitizen;
	}

	

	

