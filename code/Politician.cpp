#include <string>
#include <iostream>
#include "Politician.h"
#include "Citizen.h"

using namespace std;

	Politician::Politician() : Citizen()// default constuctor 
	{
		
		
		setType("Politician");
		//printInfo();
		

	} 

	Politician::Politician(int h , string c, string inf): Citizen( h ,  c)// param constuctor 
	{
		
		
		
		setType("Politician");
		setInfluence(inf);
		//printInfo();
		
		

	}

	
	Politician::~Politician() //destructor
	{
		//cout<<"Politician’s Destructor was Called"<<endl;
	}

	
	

	

