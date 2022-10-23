#include <string>
#include <iostream>
#include "Informant.h"
#include "Citizen.h"

using namespace std;

	Informant::Informant() : Citizen()// default constuctor 
	{
		
		setType("Informant");
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes
		

	} 

	Informant::Informant(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
		setType("Informant");
		setStatus(stat);
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes

		
		

	}

	
	Informant::~Informant() //destructor
	{
		//cout<<"Informant’s Destructor was Called"<<endl;
	}

	
<<<<<<< Updated upstream
	
=======

>>>>>>> Stashed changes
	
	

