#include <string>
#include <iostream>
#include "Soldier.h"
#include "Citizen.h"

using namespace std;

	Soldier::Soldier() : Citizen()// default constuctor 
	{
			

		setType("Soldier");
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes
		

	} 

	Soldier::Soldier(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
	
		setType("Soldier");
		setStatus(stat);
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes
		
		
		

	}

	
	Soldier::~Soldier() //destructor
	{
		// /cout<<"Soldier’s Destructor was Called"<<endl;
	}


	
	
	


