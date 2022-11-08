#include <string>
#include <iostream>
#include "Medic.h"
#include "MedicFactory.h"

using namespace std;

	MedicFactory::MedicFactory()// default constuctor 
	{
		
		//cout<<"MedicFactory’s Constructor was Called"<<endl;
		

	} 


	
	MedicFactory::~MedicFactory() //destructor
	{
		//cout<<"MedicFactory’s Destructor was Called"<<endl;
	}


	
	Citizen* MedicFactory::createCitizen()
	{
		myCitizen = new Medic();
		cout<<"Medic created"<<endl;
		cout<<endl;
		return myCitizen;
	}
	
	
	

