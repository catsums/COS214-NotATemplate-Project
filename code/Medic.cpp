#include <string>
#include <iostream>
#include "Medic.h"
#include "Citizen.h"

using namespace std;

	Medic::Medic() : Citizen()// default constuctor 
	{
		
		setType("Medic");

		printInfo();
		cout<<endl;


	} 

	Medic::Medic(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
		setType("Medic");
		setStatus(stat);
		printInfo();
		cout<<endl;


		
		

	}

	
	Medic::~Medic() //destructor
	{
		//cout<<"Medic’s Destructor was Called"<<endl;
	}

	

	

