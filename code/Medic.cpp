#include <string>
#include <iostream>
#include "Medic.h"
#include "Citizen.h"

using namespace std;

	Medic::Medic() : Citizen()// default constuctor 
	{
		
		setType("Medic");
		//printInfo();
		

	} 

	Medic::Medic(int h , string c, string stat, string theat): Citizen( h ,  c)// param constuctor 
	{
		
		setType("Medic");
		setThreatre(theat);
		setStatus(stat);
		//printInfo();

		
		

	}

	
	Medic::~Medic() //destructor
	{
		//cout<<"Medic’s Destructor was Called"<<endl;
	}

	
	
	

