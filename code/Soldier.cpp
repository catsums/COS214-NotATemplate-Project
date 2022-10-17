#include <string>
#include <iostream>
#include "Soldier.h"
#include "Citizen.h"

using namespace std;

	Soldier::Soldier() : Citizen()// default constuctor 
	{
			

		setType("Soldier");
		printInfo();
		

	} 

	Soldier::Soldier(int h , string c, string stat, string theat): Citizen( h ,  c)// param constuctor 
	{
		
	
		setType("Soldier");
		setThreatre(theat);
		setStatus(stat);
		printInfo();
		
		
		

	}

	
	Soldier::~Soldier() //destructor
	{
		cout<<"Soldier’s Destructor was Called"<<endl;
	}


	
	
	


