#include <string>
#include <iostream>
#include "Citizen.h"

using namespace std;

	Citizen::Citizen()// default constuctor 
	{
		
		cout<<"Citizen’s Constructor was Called"<<endl;
		setHp(10);
		setDamage(10);
		setCountry("SA");
		setXpos(2);
		setYpos(2);

	} 
	
	
	Citizen::~Citizen() //destructor
	{
		cout<<"Citizen’s Destructor was Called"<<endl;
	}


	

	void Citizen::takeDamage(int d)
	{
		
		hp=hp-d;
		
	}
	

	

	void Citizen::dealDamage()
	{
		
	}

	
	

	void Citizen::move(int x,int y)
	{
		xpos=x;
		ypos=y;
	}


	
	void Citizen::recieveHp(int h)
	{
		hp= hp + h;
	}

	
	
	

