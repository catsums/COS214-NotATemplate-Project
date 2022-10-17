#include <string>
#include <iostream>
#include "Medic.h"
#include "Citizen.h"

using namespace std;

	Medic::Medic() : Citizen()// default constuctor 
	{
		
		status = "NA";
		theatre = "NA";

		cout<<"Type: Medic"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<"Theatre: "<<theatre<<endl;
		cout<<endl;
		

	} 

	Medic::Medic(int h , string c, string stat, string theat): Citizen( h ,  c)// param constuctor 
	{
		
		status = stat;
		theatre = theat;

		cout<<"Type: Medic"<<endl;
		cout<<"Status: "<<status<<endl;
		cout<<"Theatre: "<<theatre<<endl;
		cout<<endl;

		
		

	}

	
	Medic::~Medic() //destructor
	{
		cout<<"Medic’s Destructor was Called"<<endl;
	}

	
	//setters
	void Medic::setStatus(string s) 
	{
		status=s;
	}

	void Medic::setThreatre(string t)
	{
		theatre = t;
	}


	//getters
	string Medic::getStatus()
	{
		return status;
	}

	string Medic::getTheatre()
	{
		return theatre;
	}

	

