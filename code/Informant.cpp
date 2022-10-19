#include <string>
#include <iostream>
#include "Informant.h"
#include "Citizen.h"

using namespace std;

	Informant::Informant() : Citizen()// default constuctor 
	{
		
		setType("Informant");
		//printInfo();
		

	} 

	Informant::Informant(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
		setType("Informant");
		setStatus(stat);
		//printInfo();

		
		

	}

	
	Informant::~Informant() //destructor
	{
		//cout<<"Informant’s Destructor was Called"<<endl;
	}

	
	
	
	

