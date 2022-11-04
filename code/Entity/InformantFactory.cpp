#include <string>
#include <iostream>
#include "Informant.h"
#include "InformantFactory.h"

using namespace std;

	InformantFactory::InformantFactory()// default constuctor 
	{
		
		//cout<<"InformantFactory’s Constructor was Called"<<endl;
		

	} 


	
	InformantFactory::~InformantFactory() //destructor
	{
		//cout<<"InformantFactory’s Destructor was Called"<<endl;
	}


	
	Citizen* InformantFactory::createCitizen()
	{
		myCitizen = new Informant();
		cout<<"Informant created"<<endl;
		cout<<endl;
		return myCitizen;
	}
	
	
	

