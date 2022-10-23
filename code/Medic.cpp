#include <string>
#include <iostream>
#include "Medic.h"
#include "Citizen.h"

using namespace std;

	Medic::Medic() : Citizen()// default constuctor 
	{
		
		setType("Medic");
<<<<<<< Updated upstream
		//printInfo();
=======
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes
		

	} 

	Medic::Medic(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
		setType("Medic");
<<<<<<< Updated upstream
		setThreatre(theat);
		setStatus(stat);
		//printInfo();
=======
		
		setStatus(stat);
		printInfo();
		cout<<endl;
>>>>>>> Stashed changes

		
		

	}

	
	Medic::~Medic() //destructor
	{
		//cout<<"Medic’s Destructor was Called"<<endl;
	}

	
	
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
	

