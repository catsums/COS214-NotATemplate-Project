#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen()// default constuctor 
	{
		HP=0;
		country=" ";
		type = "Citizen";

		//theatre = "NA";
		influence = "NA";
		status = "NA";



	} 

	Citizen::Citizen(int h , string c)// param constuctor 
	{
		HP=h;
		country=c;
		influence = "NA";
		status = "NA";


		

	}


	void Citizen::printInfo()
	{

		cout<<endl;
		cout<< "Citizen’s Information:"<<endl;
		cout<< "______________________"<<endl;
		cout<<"Health: "<<HP<<endl;
		cout<<"Country: "<<country<<endl;

		if(type== "Soldier")
		{
			cout<<"Type: Soldier"<<endl;
			cout<<"Status: "<<status<<endl;
		    //cout<<"Theatre: "<<theatre<<endl;
		}

		else if (type== "Medic")
		{
			cout<<"Type: Medic"<<endl;
			cout<<"Status: "<<status<<endl;

		}

		else if (type== "Informant")
		{
			cout<<"Type: Informant"<<endl;
			cout<<"Status: "<<status<<endl;
		}


		else if (type== "Politician")
		{
			cout<<"Type: Politician"<<endl;
			cout<<"Influence: "<<influence<<endl;
		}

		
		
	}

	
	Citizen::~Citizen() //destructor
	{
		//cout<<"Citizen’s Destructor was Called"<<endl;
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


	void Citizen::setType(string ty)
	{
		type = ty;
	}


	// void Citizen::setThreatre(string th)
	// {
	// 	theatre = th;
	// }



	void Citizen::setInfluence(string i)
	{
		influence = i;
	}

	void Citizen::setStatus(string s)
	{
		status = s;
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

	string Citizen::getType()
	{
		return type;
	}


	// string Citizen::getTheatre()
	// {
	// 	return theatre;
	// }


	string Citizen::getInfluence()
	{
		return influence;
	}

	string Citizen::getStatus()
	{
		return status;
	}
	

