#include <string>
#include <iostream>
#include "Soldier.h"
#include "Citizen.h"

using namespace std;

	Soldier::Soldier() : Citizen()
	{
			

		setType("Soldier");

		//printInfo();

		printInfo();
		cout<<endl;

		

	} 

	Soldier::Soldier(int h , string c, string stat): Citizen( h ,  c) 
	{
		
	
		setType("Soldier");
		setStatus(stat);
		printInfo();
		cout<<endl;

		
		
		

	}

	
	Soldier::~Soldier()
	{
		// /cout<<"Soldier’s Destructor was Called"<<endl;
	}


	
	
	


