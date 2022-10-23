#include <string>
#include <iostream>
#include "Politician.h"
#include "Citizen.h"

using namespace std;

	Politician::Politician() : Citizen()// default constuctor 
	{
		
		
		setType("Politician");
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes
		

	} 

	Politician::Politician(int h , string c, string inf): Citizen( h ,  c)// param constuctor 
	{
		
		
<<<<<<< Updated upstream
		
		setType("Politician");
		setInfluence(inf);
		//printInfo();
=======
		setType("Politician");
		setInfluence(inf);
		printInfo();
		cout<<endl;

>>>>>>> Stashed changes
		
		

	}

	
	Politician::~Politician() //destructor
	{
		//cout<<"Politician’s Destructor was Called"<<endl;
	}

	
	

	

