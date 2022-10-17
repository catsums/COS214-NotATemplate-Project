#include <string>
#include <iostream>
#include "Soldier.h"
#include "Citizen.h"

using namespace std;

	Soldier::Soldier() : Citizen()// default constuctor 
	{
		
		status = "NA";
		theatre = "NA";

		cout<<"Type: Soldier"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<"Theatre: "<<theatre<<endl;
		cout<<endl;
		

	} 

	Soldier::Soldier(int h , string c, string stat, string theat): Citizen( h ,  c)// param constuctor 
	{
		
		status = stat;
		theatre = theat;

		cout<<"Type: Soldier"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<"Theatre: "<<theatre<<endl;
		cout<<endl;
		
		

	}

	
	Soldier::~Soldier() //destructor
	{
		cout<<"Soldier’s Destructor was Called"<<endl;
	}


	void print()
	{
		
	}

	
	//setters
	void Soldier::setStatus(string s) 
	{
		status=s;
	}

	void Soldier::setThreatre(string t)
	{
		theatre = t;
	}


	//getters
	string Soldier::getStatus()
	{
		return status;
	}

	string Soldier::getTheatre()
	{
		return theatre;
	}



