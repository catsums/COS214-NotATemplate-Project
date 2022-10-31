#include <string>
#include <iostream>
#include "Entity.h"
#include "PoliticianFactory.h"
#include "Citizen.h"
#include "Politician.h"


using namespace std;

	PoliticianFactory::PoliticianFactory()// default constuctor 
	{

	} 

	
	PoliticianFactory::~PoliticianFactory() //destructor
	{
		cout<<"PoliticianFactory’s Destructor was Called"<<endl;
	}

	
	Citizen* PoliticianFactory::createEntity(int health,string country)
	{	
		Politician *myS= new Politician();
		Citizen *myCitizen= myS;
		myCitizen->setHP(health);
		myCitizen->setCountry(country);
		myCitizen->printInfo();
		//myS->printPoliticianInfo();



		return myCitizen;
	}

	

	

