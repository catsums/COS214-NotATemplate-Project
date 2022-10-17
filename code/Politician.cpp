#include <string>
#include <iostream>
#include "Politician.h"
#include "Citizen.h"

using namespace std;

	Politician::Politician() : Citizen()// default constuctor 
	{
		
		
		influence = "NA";

		cout<<"Type: Politician"<<endl;
		cout<<"Influence: "<<influence<<endl;
		cout<<endl;
		

	} 

	Politician::Politician(int h , string c, string inf): Citizen( h ,  c)// param constuctor 
	{
		
		
		influence = inf;

		cout<<"Type: Politician"<<endl;
		cout<<"Influence: "<<influence<<endl;
		cout<<endl;

		
		

	}

	
	Politician::~Politician() //destructor
	{
		cout<<"Politician’s Destructor was Called"<<endl;
	}

	
	//setters
	

	void Politician::setInfluence(string t)
	{
		influence = t;
	}


	//getters
	

	string Politician::getInfluence()
	{
		return influence;
	}

	

