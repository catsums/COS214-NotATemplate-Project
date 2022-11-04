#include <string>
#include <iostream>
#include "Politician.h"
#include "PoliticianFactory.h"

using namespace std;

	PoliticianFactory::PoliticianFactory()// default constuctor 
	{
		
		//cout<<"PoliticianFactory’s Constructor was Called"<<endl;
		

	} 


	
	PoliticianFactory::~PoliticianFactory() //destructor
	{
		//cout<<"PoliticianFactory’s Destructor was Called"<<endl;
	}


	
	Citizen* PoliticianFactory::createCitizen()
	{
		myCitizen = new Politician();
		cout<<"Politician created"<<endl;
		cout<<endl;
		return myCitizen;
	}
	
	
	

