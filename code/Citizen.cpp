#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen()// default constuctor 
	{
		HP=0;
		country="NA";

		cout<<endl;
		cout<< "Citizen’s Information:"<<endl;
		cout<< "______________________"<<endl;
		cout<<"Health: "<<HP<<endl;
		cout<<"Country: "<<country<<endl;

	} 

	Citizen::Citizen(int h , string c)// param constuctor 
	{
		HP=h;
		country=c;

		cout<<endl;
		cout<< "Citizen’s Information:"<<endl;
		cout<< "______________________"<<endl;
		cout<<"Health: "<<HP<<endl;
		cout<<"Country: "<<country<<endl;

	}

	
	Citizen::~Citizen() //destructor
	{
		cout<<"Citizen’s Destructor was Called"<<endl;
	}

	
	//setters
	void Citizen::setHP(int h) 
	{
		HP = h;
	}

	void Citizen::setCountry(string c)
	{
		country = c;
	}


	//getters
	int Citizen::getHP()
	{
		return HP;
	}

	string Citizen::getCountry()
	{
		return country;
	}

	

