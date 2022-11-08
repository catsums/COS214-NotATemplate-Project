#include <string>
#include <iostream>
#include "Soldier.h"
#include "SoldierFactory.h"

using namespace std;

	SoldierFactory::SoldierFactory()// default constuctor 
	{
		
		//cout<<"SoldierFactory’s Constructor was Called"<<endl;
		

	} 


	
	SoldierFactory::~SoldierFactory() //destructor
	{
		//cout<<"SoldierFactory’s Destructor was Called"<<endl;
	}


	
	Citizen* SoldierFactory::createCitizen()
	{
		myCitizen = new Soldier();
		cout<<"Soldier created"<<endl;
		cout<<endl;
		return myCitizen;
	}
	
	
	

