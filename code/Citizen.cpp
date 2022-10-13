#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen()// default constuctor 
	{
		HP=0;
		Country="NA";

		cout<< "Citizen’s Information:"<<endl;
		cout<<"Health: "<<HP<<endl;
		cout<<"Country: "<<Country<<endl;

	} 

	Citizen::Citizen(int h , string c)// param constuctor 
	{
		HP=h;
		Country=c;

		cout<< "Citizen’s Information:"<<endl;
		cout<<"Health: "<<HP<<endl;
		cout<<"Country: "<<Country<<endl;

	}

	
	Citizen::~Citizen() //destructor
	{
		cout<<"Citizen’s Destructor was Called"<<endl;
	}

	
	//setters
	void Citizen::setHP() 
	{

	}

	void Citizen::setCountry()
	{

	}


	//getters
	int Citizen::getHP()
	{
		return HP;
	}

	string Citizen::getCountry()
	{
		return Country;
	}

	

