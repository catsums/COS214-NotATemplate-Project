#include <string>
#include <iostream>
#include "Entity.h"
#include "SoldierFactory.h"
#include "Citizen.h"
#include "Soldier.h"


using namespace std;

	SoldierFactory::SoldierFactory()// default constuctor 
	{

	} 

	
	SoldierFactory::~SoldierFactory() //destructor
	{
		cout<<"SoldierFactory’s Destructor was Called"<<endl;
	}

	
	Citizen* SoldierFactory::createEntity(int health,string country)
	{
		Citizen *myCitizen= new Soldier();
		myCitizen->setHP(health);
		myCitizen->setCountry(country);
		return myCitizen;
	}

	

	

