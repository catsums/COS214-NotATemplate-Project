#include <string>
#include <iostream>
#include "Informant.h"
#include "Citizen.h"

using namespace std;

	Informant::Informant() : Citizen()// default constuctor 
	{
		
		status = "NA";
		

		cout<<"Type: Informant"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<endl;
		

	} 

	Informant::Informant(int h , string c, string stat): Citizen( h ,  c)// param constuctor 
	{
		
		status = stat;
		

		cout<<"Type: Informant"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<endl;

		
		

	}

	
	Informant::~Informant() //destructor
	{
		cout<<"Informant’s Destructor was Called"<<endl;
	}

	
	//setters
	void Informant::setStatus(string s) 
	{
		status=s;
	}

	


	//getters
	string Informant::getStatus()
	{
		return status;
	}

	
	

